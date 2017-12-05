#lang racket

;; LET IS LAMBDA

;; You may have started using "local variables" inside procedures with
;; the "let" statement.
;;
;; In fact, "let" is syntactic sugar for dynamically creating a lambda
;; context and then populating its parameters with values. The
;; parameters of the lambda act like local variables.

;; These exercises below are based on the book section
;; "Using let to create local variables" at pp. 85 to 88 of the SICP PDF file.
;; This is in Section 1.3.2, "Constructing Procedures Using Lambda" at
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-12.html#%_sec_Temp_100

;; Please read the above before attempting the exercises.

;; NOTE: THESE WILL APPEAR CORRECT AS RECEIVED VIA THE AUTOGRADER
;; but that simply means that they are presently calculating the
;; correct values.

;; these exercises are about re-writing let's as lambda's and vice-versa,
;; so the human graders will mark them based on you having done this.

;; do not remove
(define square (lambda (x) (* x x)))

;; in the following procedures, rewrite to be equivalent
;; by transforming the let expressions into lambda's


(define (proc1 x y)
  (let ((a (+ x y))
	(b (- x y)))
    (+ (square a) (square b))))

(define (proc2 n)
  (let ((a (+ n 1))
	(b (+ n 2))
	(c (+ n 3)))
    (* a b c)))

(define (proc3 n)
  (let ((a (+ n 1)))
    (let ((b (* a 2)))
      (+ a b))))

;; in the following procedures, rewrite to be equivalent
;; by transforming the lambda expressions into let's

(define (proc4 x y)
  ((lambda (a b) (* a b))
   (* 3 x) (/ y 4)))

(define (proc5 n)
  ((lambda (y z) (* (- y 1) (- z 1)))
   (* n 2) (- n 3)))

(define (proc6 a b c)
  ((lambda (n)
     ((lambda (m)
        (* n m))
      (+ a n)))
   (+ b c)))

;; There is also a version of let, named "let*", where you write a
;; series of let's, but this series is transformed into a nested
;; composition of lets.
;;
;; e.g., in the example proc6 above, when the "lambda (m) ..."
;; evaluates, the symbol "n" will be bound to a concrete value.
;;
;; Read more about let* in Exercise 4.7
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-26.html#%_idx_4408
;; 
;; or on p. 510 of the Github SICP PDF.
;;
;; Re-write this procedure using let*.

(define (proc6-star a b c)
  ((lambda (n)
     ((lambda (m)
        (* n m))
      (+ a n)))
   (+ b c)))
