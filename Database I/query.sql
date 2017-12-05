-- Name: Chuong Vu

/* Queries tables 
course (course_id, title, dept_name, credits)
instructor (ID, name, dept_name, salary)
teaches (ID, course_id, sec_id, semester, year)
student (ID, name, dept_name, tot_cred)
takes (ID, course_id, sec_id, semester, year, grade)

*/

/* Pre-setup display for easy to look */
clear break
clear comp
clear col
SET HEADING ON
SET PAGESIZE 30
set linesize 9999
set trimspool ON
set tab off
set echo off
set recsep off


-- 1. Find the student's name whose ID = "113". */

SELECT name 
FROM student 
WHERE id='113';

-- 2. List all courses which title starts with "G"

SELECT * 
FROM course 
WHERE title 
LIKE 'G%';

-- 3. List all instructor IDs who did not teach any courses in Fall 2016.
-- SELECT DISTINCT * FROM INSTRUCTOR NATURAL JOIN TEACHES WHERE SEMESTER!='Fall' AND YEAR!='2016' ORDER BY ID;

SELECT id 
FROM instructor 
WHERE id 
NOT IN (SELECT id 
		FROM teaches 
		WHERE semester='Fall' 
		AND year=2016);

-- 4. Find the total number of students in each department. Display the number in ascending order.
SELECT DEPT_NAME, COUNT(DEPT_NAME) CNT
FROM student
GROUP BY dept_name
ORDER BY CNT ASC;

-- 5. Find the name of instructor who teaches the most students.
-- Shortest Method

SELECT instructor.id, instructor.name 
FROM instructor,
	(SELECT teaches.id
	FROM teaches INNER JOIN takes 
	ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year
	GROUP BY teaches.id 
	HAVING COUNT(teaches.id) = 
		(SELECT MAX(COUNT(teaches.id))
		FROM teaches INNER JOIN takes 
		ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year 
		GROUP BY teaches.id) 
	) idtable
WHERE instructor.id = idtable.id;


/*
-- new method
SELECT ins.id, ins.name 
FROM instructor ins,
	(SELECT t1.id, COUNT(t1.id)
	FROM (SELECT teaches.id id, takes.id studentid, takes.course_id, takes.sec_id, takes.semester, takes.year 
		FROM teaches INNER JOIN takes 
		ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year 
		ORDER BY takes.year) t1
	GROUP BY id 
	HAVING COUNT(t1.id) = 
		(SELECT MAX(COUNT(teachid)) 
		FROM (SELECT teaches.id teachid, takes.id studentid, takes.course_id, takes.sec_id, takes.semester, takes.year 
			FROM teaches INNER JOIN takes 
			ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year 
			ORDER BY takes.year) 
		GROUP BY teachid)
	) rs
WHERE ins.id = rs.id;

*/

-- Method 2, use more select
/*
SELECT ins.id, ins.name FROM instructor ins, 
	(SELECT t2.teachid, t1.cnt 
	FROM (SELECT max(cnt) cnt 
		FROM (SELECT id, count(*) cnt 
			FROM (SELECT teaches.id id, takes.id studentid, takes.course_id, takes.sec_id, takes.semester, takes.year 
				FROM teaches INNER JOIN takes 
				ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year 
				ORDER BY takes.year) 
			GROUP BY id)
		) t1, 
		(SELECT id teachid, cnt 
		FROM (SELECT id, count(*) cnt 
			FROM (SELECT teaches.id id, takes.id studentid, takes.course_id, takes.sec_id, takes.semester, takes.year 
				FROM teaches INNER JOIN takes 
				ON takes.course_id = teaches.course_id AND takes.sec_id = teaches.sec_id AND takes.semester = teaches.semester AND takes.year = teaches.year 
				ORDER BY takes.year) 
			GROUP BY id)
		) t2 
	WHERE t1.cnt = t2.cnt) rs 
WHERE rs.teachid = ins.id;

*/

-- 6. List all instructors who teach in all those years that the instructor "McKinnon" teaches.
-- I remove the name of McKinnon in the list
-- Should return nothing

SELECT teaches.id, instructor.name 
FROM teaches INNER JOIN instructor 
ON teaches.id = instructor.id 
WHERE teaches.year IN 
	(SELECT DISTINCT t.year 
	FROM teaches t, instructor i 
	WHERE i.name='McKinnon' AND t.id=i.id) AND instructor.name != 'McKinnon'
GROUP BY teaches.id, instructor.name
ORDER BY teaches.id;


-- 7. For the department WHERE the instructors have the highest average salary, list the top 2 instructors who have the highest salaries AND their salaries.

-- new method
SELECT name, salary 
FROM instructor 
WHERE dept_name = 
	(SELECT t1.dept_name 
	FROM instructor t1
	GROUP BY t1.dept_name
	HAVING AVG(t1.salary) >=
		(SELECT MAX(AVG(salary)) 
		FROM instructor 
		GROUP BY dept_name))
AND ROWNUM <= 2 
ORDER BY salary DESC;


/*
Old method

SELECT name, salary 
FROM instructor 
WHERE dept_name = 
	(SELECT t2.dept_name 
	FROM (SELECT max(avg(salary)) max 
		FROM instructor 
		GROUP BY dept_name) t1, 
	(SELECT dept_name, avg(salary) avg_salary 
		FROM instructor 
		GROUP BY dept_name) t2 
	WHERE t1.max = t2.avg_salary) 
AND rownum <=2 
ORDER BY salary DESC;

*/

-- 8. Generate "transcript records" for all students of "Comp. Sci." department. A transcript record should include student name, course title, the year and semester when the student took this course, the credits of this course and the grade of the student on this course. The transcript records from one student should be shown together, and in year, semester descending order. Return only 5 of those transcript records.

WITH st AS
 (SELECT  id, name
  FROM (SELECT *
		FROM student 
		WHERE dept_name='Comp. Sci.' 
		ORDER BY name) 
   WHERE ROWNUM <=5)
SELECT st.name, course.title, takes.semester, takes.year, takes.grade, course.credits
FROM st, takes INNER JOIN course 
ON course.course_id=takes.course_id 
WHERE takes.id=st.id
ORDER BY name;


-- 9. Increase the salary of instructors whose salary <= 50000 by 10000.

UPDATE instructor 
SET salary = salary + 10000 
WHERE salary <= 50000;

-- 10. Delete all the records in table "takes" which students' name = "Tomason".

DELETE FROM takes
WHERE id 
IN (SELECT id 
    FROM student 
	WHERE name='Tomason');












