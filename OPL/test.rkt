#lang racket


(define (merge list1 list2)
  (cond ((null? list1) list2)
        ((null? list2) list1)
        ((= (car list1) (car list2))
         (cons (car list1)
               (merge (cdr list1) (cdr list2))))
        ((< (car list1) (car list2))
         (cons (car list1)
               (merge (cdr list1) list2)))
        (else (cons (car list2) (merge list1 (cdr list2))))))



(define ls1 '(1 3))
(define ls2 '(2 4 6 8 10 12))


;'(cddr ls1)

(define (apply-twice f)
 (lambda (x) (f (f x))))

(define f (lambda (a b) (* a b b)))
;(f 3 2)

(define inc
  (lambda (n) (+ n 1)))

(define (double f)
  (lambda (x) (f (f x))))

;((double (double inc)) 3)



(define (g)
  (lambda (a b) (+ a b)))

(define a (cons 1( cons 2 (list 3 4))))


(define b
  (cons (list 1 (list 2 3)) (cons 4 5)))


(define (sum-even-leave tree)




