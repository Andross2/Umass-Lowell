#lang racket

;; last updated Mon Feb  6 13:14:35 2017 fred_martin@uml.edu

;; +++++++++++++++ Required for auto grading ++++++++++++++++++++++++++++
(define nil '())

(define (square x) (* x x))

(define (scale-list items factor)
  (if (null? items)
      nil
      (cons (* (car items) factor)
            (scale-list (cdr items) factor))))

(define (accumulate op initial sequence)
  (if (null? sequence)
      initial
      (op (car sequence)
          (accumulate op initial (cdr sequence)))))

;; ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;; Write a procedure called double-list in three different ways:
;; #1 Write a list manipulation procedure of your own to do this.
;; #2 Use the scale-list procedure on pp. 105 in your definition.
;; #3 Use the map procedure on pp. 105 in your definition.

;a)
(define (double-list1 lst)
 (accumulate (lambda (a  b) (cons (* 2 a) b)) '() lst))

;b)
;; using scale-list 
(define (double-list2 lst)
  (scale-list lst 2))

;c)
;; using map
(define (double-list3 lst)
  (map (lambda (a) (* a 2)) lst))

;; SICP exercise 2.21 (pp. 106), on square-list.

(define (square-list1 items)
 (if (null? items) nil
      (cons (square (car items))
            (square-list1 (cdr items)))))

(define (square-list2 items)
  (map (lambda (a) (square a)) items))

;; enum-range is a procedure that generates a list of ints
;; beginning with "a" and ending with "b" (inclusive).
;; here is a recursive-process definition:
(define (enum-range a b)
  (if (> a b)
      '()
      (cons a (enum-range (+ a 1) b))))

;; write an iterative-process version of this.
(define (enum-range-i a b)
  (define (iter start end lst)
    (if (> start end) lst
        (cons start (iter (+ start 1) end lst))))
  (iter a b '()))

;; this is a list of the first 100 natural numbers
(define my-nats (enum-range-i 1 100))

;; using any combinations of maps, filters, accums create the following
;; numeric sequences or values

;; all odd numbers
(define (odds lst) 
  ;; some map/filter expr over
  (filter odd? lst))

;; each number tripled
;; e.g. 3, 6, 9, ... , 300
(define (triples lst)
  ;; maps and/or filters over
  (map (lambda (a) (* a 3)) lst))

;; sum of squares
;; i.e., 1 + 4 + 9 + 16 + ... + 10000
(define (square-sum lst)
  ;; probably an accumulation is involved here
   (accumulate + 0 (square-list1 lst)))

;; product of each item
;; = 1 * 2 * 3 * ... * 100
(define (products lst)
  (accumulate * 1 lst))

;; suppose we have a list of lists.
;; each sublist contains two numbers; e.g.:
;; '((1 2) (3 4) (5 6) (7 8) ... (99 100))
;; write a fcn to accumulate the sum of the products
;; of each of the sublist pairs; i.e.:
;;
;; (1 * 2) + (3 * 4) + ... + (99 * 100)

(define (pair-seq a b)
  (if (> a b)
      '()
      (cons (list a (+ a 1))
	    (pair-seq (+ a 2) b))))

(define my-nat-pairs (pair-seq 1 100))

;; write the accumulation function here
(define (sum-of-prod-lists lst)
  ;; some accum
 (accumulate + 0 (map (lambda (lst)
                       (* (car lst) (cadr lst)))
                       lst))) 

;; SICP exercise 2.35 (pp. 120), redefining count-leaves as an
;; accumulation.  Fill in the below procedure. Replace '<??>.
;; note! you may recursively call this "count-leaves" fcn
;;  inside of it!
;; e.g.:
;;  (define tree (list 1 2 (list 3 4) (list 5 (list 6 7)))) 
;;  (count-leaves tree) => 7

(define (count-leaves tree)
  (cond ((null? tree) 0)
        ((not (pair? tree)) 1)
        (else (accumulate + 0 (map count-leaves tree)))))

;; SICP exercise 2.33 (pp. 119), implementing map, append, and
;; length.  Replace '<??> with answer
;;
;; this are tricky little gems!
;; don't look up the answers -- struggle with them!
;;
;; to get credit for these, you must show your work. That might consist
;; of partially-working / partially-broken steps along the way to an
;; answer, or a narrative of what you were thinking about as you worked
;; your way to an answer.

(define (map-from-fold p sequence)
  (accumulate (lambda (x y) (cons (p x) y)) nil sequence))

(define (append-from-fold seq1 seq2)
  (accumulate cons '() (append seq1 seq2)))

(define (length-from-fold sequence)
  (accumulate (lambda (a b) (+ b 1)) 0 sequence))

;; think back to the sum-of-prod-lists problem a little while back.
;; now let's do it with a flat list; e.g.
;; if given: '(1 2 3 4 .... 99 100)
;; we want: (1 * 2) + (3 * 4) + ... (99 * 100)
;; you may assume the input list has an even # of elements

(define (pair lst)
  (if(null? lst)
     '()
      (cons (list (car lst) (car(cdr lst))) (pair (cdr (cdr lst))))))
                 

;; this is not trivial!
;; the trick is to transform thing coming out of each accum
;; step into two different things depending on whether
;; you've just computed a product, or need to carry forward
;; a multiplicand to the next operation
(define (sum-of-prods lst)
 (accumulate (lambda (n b) (+ (* (car n) (car(cdr n))) b))
             0
             (pair lst)))
 
;; just need a single accumulation if it's done right

;; Solve SICP exercise 2.27 on deep-reverse.
;;
;; Note: it is be easy enough to Google for the answer on this.
;; Obviously this will short-circuit your learning.  So don't do that.
;;
;; TO GET CREDIT FOR THIS: 
;;
;; Show steps along the way to your solution -- e.g., partly working
;; code, what inputs you tested it on, what results it produced, what
;; you did next.
;; 
;; No one spits out a solution for this fully-formed... 

; my-reverse
; this should be reverse the items at the top level of the list
; do this as warm-up
; e.g. 
;  (my-reverse '(1 2 3)) => '(3 2 1)
;  (my-reverse '((1 2) (3 4))) => '((3 4) (1 2))

(define (my-reverse items) 
   (if (null? items) nil
      (append (my-reverse (cdr items)) (list (car items)))))

; deep reverse
; recursively reverse sublists
; e.g.
;  (deep-reverse '(1 2 3)) => '(3 2 1)
;  (deep-reverse '((1 2) (3 4))) => '((4 3) (2 1))
;  (deep-reverse '((1 2) (3 (4 5)))) => '(((5 4) 3) (2 1))

(define (deep-reverse items) 
  (cond ((null? items) nil) ;; if the list is null, return nil.
        ;; and if the element of the list is a pair,
        ;; recursively call deep-reverse funciton,
        ;; and make a new list because in the list there is still other pairs
        ((pair? (car items)) 
         (append (deep-reverse (cdr items)) (list (deep-reverse (car items)))))
        ;; otherwise, recursively call deep-reverse function then make a new list for the reversed list.
        (else (append (deep-reverse (cdr items)) (list (car items))))))

