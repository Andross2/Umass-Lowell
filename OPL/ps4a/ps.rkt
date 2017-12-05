#lang racket

;; BEFORE DOING THESE EXERCISES, READ
;; SICP Chapter 3, "Modularity, Objects, and State"
;; all the way through 3.2.3 "Frames as the Repository of Local State"
;; this means all of these sections:
;; 3  Modularity, Objects, and State
;;        3.1  Assignment and Local State
;;            3.1.1  Local State Variables
;;            3.1.2  The Benefits of Introducing Assignment
;;            3.1.3  The Costs of Introducing Assignment
;;        3.2  The Environment Model of Evaluation
;;            3.2.1  The Rules for Evaluation
;;            3.2.2  Applying Simple Procedures
;;            3.2.3  Frames as the Repository of Local State
;;
;; start here
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-19.html#%_chap_3
;;
;; or pp. 294-335 of the Github PDF of SICP.

;; Exercise 3.1
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-20.html#%_thm_3.1
;; 
;; After writing and testing the code, draw the environment diagram that would
;; result from evaluating the three statements in the exercise.
;; 
;; Include as ASCII drawing in this file, or upload image named
;; exercise3.1-env.png (or .jpg)

(define (make-accumulator sum)
  (lambda (n) (begin (set! sum (+ sum n))) sum))

(define exercise-3.1-env #t)
;; change to #t after you include diagram

;; Exercise 3.2
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-20.html#%_thm_3.2
;;
;; After writing and testing the code, draw the environment diagram that would
;; result from evaluating the three statements in the exercise.
;; 
;; Include as ASCII drawing in this file, or upload image named
;; exercise3.2-env.png (or .jpg)

(define (make-monitored value)
  (let ((count 0))
    (lambda (n)
      (cond
        [(equal? n 'how-many-calls?) count]
        [(equal? n 'reset-count) (set! count 0)]
        [else (begin (set! count ( + 1 count)) (value n))]
        ))))

(define exercise-3.2-env #t)
;; change to #t after you include diagram


;; Exercise 3.3
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-20.html#%_thm_3.3
(define (make-account balance main-password)
  (define (withdraw amount)
    (cond ((> amount balance) "Fail to withdraw")
          (else (set! balance (- balance amount)) balance)))
  (define (deposit amount)
    (set! balance (+ balance amount)) balance)
  (define (bad-password ignored) "Incorrect password")
  (lambda (password operation)
    (cond [(not (equal? password main-password)) bad-password]
          [(equal? operation 'withdraw) withdraw]
          [(equal? operation 'deposit) deposit])))
                                       
;; Exercise 3.4
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-20.html#%_thm_3.4
;;
;; this procedure should be called "make-account-secure"
;;
;; important note:
;;   once an account is locked, you should not be able to withdraw funds
;;   from it, even if then using the correct password!
(define (make-account-secure balance pass)
  (let([count 0])
    (define (withdraw amount)
      (set! count 0)
      (if (>= balance amount)
          (begin (set! balance ( - balance amount)) balance) "Insufficient funds"))

    (define (deposit amount)
      (set! count 0)
      (set! balance (+ balance amount)) balance)

    (define (wrong-pass amount)
      (if (< count 7)
          (begin (set! count (+ count 1)) "Incorrect Password")
          (begin (set! count (+ count 1)) (call-the-cops))))
    (define (dispatch pwd m)
      (if (and (eq? pass pwd) (<= count 7))
          (cond [(eq? m 'withdraw) withdraw]
                [(eq? m 'deposit) deposit]
                [else (error "Unknown request" m)])
          wrong-pass))
    dispatch))

    

  
; don't modify this
(define (call-the-cops)
  "your account has been locked. please call customer service.")
  