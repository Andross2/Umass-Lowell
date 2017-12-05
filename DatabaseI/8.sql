-- 8. Generate "transcript records" for all students of "Comp. Sci." department. A transcript record should include student name, course title, the year and semester when the student took this course, the credits of this course and the grade of the student on this course. The transcript records from one student should be shown together, and in year, semester descending order. Return only 5 of those transcript records.

-- student name, course title, the year and semester


select takes.course_id from student inner join takes 
on student.id=takes.id 
WHERE student.id in (select id from student where rownum <=5 and dept_name='Comp. Sci.')
order by student.id asc;


select student.name, t1.title, t1.semester, t1.year, t1.grade, t1.credits
from (select takes.id id, takes.course_id, takes.semester, takes.year, takes.grade, course.title, course.credits from takes inner join course on takes.course_id=course.course_id) t1 inner join student on t1.ID = student.id 
WHERE student.id in (select id from student where rownum <=5 and dept_name='Comp. Sci.')
order by student.name asc;

select student.name, t1.title, t1.semester, t1.year, t1.grade, t1.credits
from (select takes.id id, takes.course_id, takes.semester, takes.year, takes.grade, course.title, course.credits 
	from takes inner join course 
	on takes.course_id=course.course_id) t1 
inner join student 
on t1.ID = student.id 
WHERE student.id 
in (select id 
	from student 
	where rownum <=5)
order by student.name asc;

with t as
 (select * from student order by student.name)
select * from t where rownum <=5;


select * from student order by name;





;
WITH st AS
 (select * from (SELECT id, name 
  FROM student 
  WHERE dept_name='Comp. Sci.' 
  ORDER BY name) where rownum <=5)
SELECT st.name, course.title, takes.semester, takes.year, takes.grade, course.credits
FROM st, takes INNER JOIN course 
ON course.course_id=takes.course_id 
WHERE takes.id=st.id
ORDER BY name;


WITH st AS
 (SELECT * 
  FROM (SELECT id, name 
		FROM student 
		WHERE dept_name='Comp. Sci.' 
		ORDER BY name) 
   WHERE ROWNUM <=5)
SELECT st.name, course.title, takes.semester, takes.year, takes.grade, course.credits
FROM st, takes INNER JOIN course 
ON course.course_id=takes.course_id 
WHERE takes.id=st.id
ORDER BY name;













