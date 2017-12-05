#lang racket

;; BEFORE DOING THIS PROBLEM SET, READ:
;; Section 1.3, "Formulating Abstractions with Higher-Order
;; Procedures"
;; pp 74 - 79 of SICP PDF file
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-12.html#%_sec_1.3
;;
;; and
;;
;; Section 1.3.4 "Procedures as returned values"
;; pp 97 - 103 of SICP PDF file
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-12.html#%_sec_1.3.4

;; You may use these functions in your solutions!
;; 
;;+++++++++++++++ Required for auto grading; don't remove +++++++++++++
(define (square x) (* x x))
(define (identity x) x) 
(define (next x) (+ x 1)) 
(define (inc n) (+ n 1))
;;+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

;; SICP exercise 1.30 (pp. 60), convert the recursive implementation
;; to iterative.
;;
;; Un-comment and fill in the below procedure
;; "term" is a procedure that transforms parameter "a"
;; "next" is a procedure acts as the successor function

(define (sum term a next b)
   (define (iter a result)
     (if (> a b)
 	result
       (iter (next a) (+ (term a) result))))
   (iter a 0))
      ;; get rid of this line when you comment-in the body stub.


;; Working towards higher-order procedures: Do SICP exercise 1.31 (a)
;; and (b) (pp. 60–61).  fill in the below procedures

;; (a) Recursive product procedure
(define (product1 term a next b) 
  (if (> a b)
      1
      (* (term a)
         (product1 term (next a) next b))))

;; factorial procedure in terms of product
(define (factorial n)
 (product1 identity 1 inc n)
)

;; Approximations to pi using john wallis' formula
;; Starting at 1 and incrementing by 1, each successive pi-term
;; should generate the next fraction in the Wallis series; e.g.:
;;
;; (pi-term 1) => 2 / 3
;; (pi-term 2) => 4 / 3
;; (pi-term 3) => 4 / 5
;; etc.
(define (pi-term n) 
;  (define (pi-cal a b counter n)
;    (cond
;      [(> counter n) (/ a b)]
;      [(> b a) (pi-cal (+ a 2) b (+ counter 1) n)]
;      [(> a b)  (pi-cal a (+ b 2) (+ counter 1) n)]
;      ))
;  (pi-cal 2 1 1 n))

  (if (even? n)
      (/ (+ n 2) (+ n 1))
      (/ (+ n 1) (+ n 2))))
;; e.g.,
;; (* (product1 pi-term 1 next 6) 4)
;; = 3.3436734693877552 or 3 421/1225


;; (b) Iterative product procedure
(define (product2 term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a)
              (* (term a) result))))
  (iter a 1))

;; SICP exercise 1.32 (a only): Implement accumulate and show how sum
;; and product can be defined with calls to accumulate. Specify
;; whether you have built the iterative or recursive version.  fill in
;; the below procedures

;; (a) Recursive process
(define (accumulate combiner null-value term a next b)
  (cond
    [(> a b) null-value]
    [else (combiner (term a)
                   (accumulate combiner null-value term (next a) next b))]
    ))

(define (sum1 term a next b)
  (accumulate + 0 term a next b))

(define (product term a next b)
  (accumulate * 1 term a next b))

;; (b) Iterative process
(define (accumulate1 combiner null-value term a next b)
  (define (iter a result)
    (if (> a b)
        result
        (iter (next a) (combiner (term a) result))))
  (iter a null-value))

;; SICP exercise 1.41 (pp. 77): Procedures that return procedures.
;; e.g.
;;  ((double inc) 3) is 5
;;  (((double double) inc) 3) is 7
;;  (((double (double double)) inc) 5) is 21
(define (double f) 
  (lambda (z) (f (f z))))

;; SICP exercise 1.42 (pp. 77): More procedures that return procedures.
;; e.g.,
;;  ((compose inc square) 6) is 37
;;  ((compose square inc) 6) is 49
;;  ((compose (compose square square) square) 2) is 256
;;  ((compose square (compose square square)) 2) is also 256
(define (compose f g) 
  (lambda (z) (f (g z))))

;; Here is an implementation of expnt, a procedure that generates
;; a procedure for raising its input to its argument.
;;
;;     E.g., (expnt 2) generates a procedure for squaring a
;;     number. The provided implementation of expnt generates a
;;     recursive process. Re-implement it as an iterative process
;;     (probably using a helper procedure).
;;
;; generates a procedure that raises its argument to the nth power
;; Recursive process
;; e.g. ((expnt 0) 10) is 1     (10^0)
;;      ((expnt 1) 10) is 10    (10^1)
;;      ((expnt 2) 10) is 100   (10^2)
;;      ((expnt 3) 10) is 1000  (10^3)
(define (expnt n)
  (if (= n 0) (lambda (x) 1)
      (if (= n 1)
          (lambda (x) x)
          (lambda (x) (* x ((expnt (- n 1)) x))))))

;Iterative process 
(define (expnt-iter n)
  (define (expnt-helper result counter max)
    (if (= counter 0)
        result
        (expnt-helper (* max result) (- counter 1) max)))
  (lambda (x) (expnt-helper 1 n x)))


;; the below is not graded; it won't be counted.
;; 
;; Honors, Graduate Students, and Undergrads Looking for More
;; 11. SICP exercise 1.43 (pp. 77): Repeated application of procedures.
;; fill in the below procedure

;; e.g., ((repeat square 2) 5) is 625

;;(define (repeat f n) 
;;  1) 


;;****************************** END OF FILE ******************************


