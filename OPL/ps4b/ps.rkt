#lang racket

;; READ BEFORE DOING THIS
;; SICP Section 2.1.3 What Is Meant by Data?
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-4.html#%_toc_%_sec_2.1.3

;; Introduction:
;; Amazingly, procedural closures can be used to implement the
;; equivalent of the cons cell.
;;
;; that is, strictly speaking, the facility of the cons cell
;; abstraction (including the "cons" constructor, and the "car" and
;; "cdr" selectors), can be implemented ONLY USING PROCEDURES.
;;
;; demonstrating this is the point of this exercise.
;; 
;; SICP exercise 2.4 -- using procedure closures to implement cons.
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-14.html#%_thm_2.4
;;
;; Here is an alternative procedural representation of pairs. Note that
;; (my-car (my-cons x y)) yields x for any objects x and y.
;;
;; Based on this definition of cons, implement the corresponding car
;; and cdr selectors. (Name them "my-car" and "my-cdr".)

(define (my-cons x y)
  (lambda (m) (m x y)))

;; what is the corresponding definition of my-cdr? (Hint: To verify
;; that this works, make use of the substitution model of Section
;; 1.1.5.) 

(define (my-car z)
  (z (lambda (x y) x)))

(define (my-cdr z)
  (z (lambda (x y) y)))


;; now, make an environment diagram to show what is created when
;; the following statement is evaluated:
;;
;; (define foo (my-cons (3 4))
;;
;; make sure to create a binding for "foo" in the global environment
;; and have it point at the procedure closure with appropriate
;; binding in any additional environment frames
;;
;; submit your drawing as a JPG image or as
;; commented-out ASCII art in this file
;; change the following symbol from #f to #t when it's done
(define env-diagram #t)


;; some tests
;(begin (define cons1 (my-cons 'bar '()))
;       (define cons2 (my-cons 'foo cons1))
;       (my-car (my-cdr cons2)))
;
;(begin (define cons3 (my-cons 'bar '()))
;       (define cons4 (my-cons 'foo cons3))
;       (define cons5 (my-cons 'cat cons4))
;       (my-car (my-cdr (my-cdr cons5))))
