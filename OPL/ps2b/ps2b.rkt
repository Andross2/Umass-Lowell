#lang racket

;; ps2c.rkt
;; last modified Thu Feb  4 20:13:43 2016 fredm@cs.uml.edu

;; before doing this, read:
;; SICP Chapter 2 intro
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-13.html#%_chap_2
;;
;; SICP Section 2.1, Introduction to Data Abstraction
;; https://mitpress.mit.edu/sicp/full-text/book/book-Z-H-14.html#%_sec_2.1

;; SICP exercise 2.2 (pp. 89-90). In this problem you create data
;; structures in Scheme representing line segments in a plane.

(define (print-point p) 
   (newline) 
   (display "'(")   ;;don't remove the single quote. It is needed for
		    ;;auto grader
   (display (x-point p)) 
   (display ", ") 
   (display (y-point p)) 
   (display ")")) 

;; Fill in the below procedures  
;;
;; the idea here is that you are creating an abstraction of the X,Y
;; point object.
;; 
;; make-point is the constructor and x-point and y-point are the
;; selectors. 
;; 
;; you can use any internal representation you like as long as the
;; constructor and selectors are consistent with the internal
;; representation. 
;; Point
(define (make-point x y) ;; make new pair
  (cons x y))

;; return the first element of the pair
(define (x-point p) 
  (car p))

;; return the second element of the pair
(define (y-point p) 
  (cdr p))
 
;; Segment 
;; similarly, make-seg is the constructor;
;; start-seg and end-seg are accessors.
;; midpoint-seg is an accessor that finds the midpoint of the line
;; segment. 
;; make sure to use your point object inside your line segment!
;; (two of them)
(define (make-seg start-point end-point) 
  (cons start-point end-point))

(define (start-seg segment) 
  (car segment))

(define (end-seg segment)
  (cdr segment))
  
 ; should return a point
(define (midpoint-seg segment)
  (cons (/ (+ (x-point (start-seg segment)) (x-point (end-seg segment))) 2)
        (/ (+ (y-point (start-seg segment)) (y-point (end-seg segment))) 2)
        )
   )
  
;; SICP exercise 2.3 (pp. 90). Here you represent rectangles and
;; construct procedures to compute perimeter and area.  Fill in the
;; below procedures
;; more constructors and selectors
;; you may use your point objects if you desire 

(define (make-rect x1 y1 x2 y2)
  (cons (make-point x1 y1) (make-point x2 y2)))

(define (corner1 rect)
  ; should return some kind of object representing a corner
  (cons (x-point (start-seg rect)) (y-point (start-seg rect))))

(define (corner2 rect)
  ; should return the diagonally opposite corner
 (cons (x-point (end-seg rect)) (y-point (end-seg rect))))

(define (width rect)
  ; must use corner1 and corner2 selectors
  (abs (- (x-point (corner2 rect)) (x-point (corner1 rect)))))

(define (height rect) 
  ; must use corner1 and corner2 selectors
  (abs (- (y-point (corner2 rect)) (y-point (corner1 rect)))))
  
;; area and perimeter 
;; must use your width and height abstractions!
(define (area rect) 
  (* (width rect ) (height rect)))

(define (perimeter rect) 
  (* (+ (width rect) (height rect)) 2))
