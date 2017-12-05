-- Name: Chuong Vu

/* Need to drop the one have foreign key constraint first before drop the one depend on it */
DROP TABLE course;
DROP TABLE teaches;
DROP TABLE instructor;
DROP TABLE takes;
DROP TABLE student;

/* this is command to create table */
/* to run this out side from the sql, we run command
	sqlplus cvu@cvu @"create_table.sql"
*/

CREATE TABLE course (
	course_id int NOT NULL,
	title char(30),
	dept_name char(20),
	credits int,
	CONSTRAINT course_pk PRIMARY KEY(course_id)
);

CREATE TABLE instructor (
	ID int NOT NULL,
	name char(20),
	dept_name char(20),
	salary int,
	CONSTRAINT instructor_pk PRIMARY KEY(ID)
);

CREATE TABLE teaches (
	ID int NOT NULL,
	course_id int NOT NULL,
	sec_id int NOT NULL,
	semester char(10) NOT NULL,
	year int NOT NULL,
	CONSTRAINT teaches_pk PRIMARY KEY(ID,course_id,sec_id,semester,year),
	CONSTRAINT teaches_fk FOREIGN KEY(ID) REFERENCES instructor(ID)
);

CREATE TABLE student (
	ID int NOT NULL,
	name char(20),
	dept_name char(20),
	tot_cred int,
	CONSTRAINT student_pk PRIMARY KEY(ID)
);

CREATE TABLE takes (
	ID int NOT NULL,
	course_id int NOT NULL,
	sec_id int NOT NULL,
	semester char(10) NOT NULL,
	year int NOT NULL,
	grade char(5),
	CONSTRAINT takes_pk PRIMARY KEY(ID,course_id,sec_id,semester, year),
	CONSTRAINT take_fk FOREIGN KEY(ID) REFERENCES student(ID)
);

/* Use to display the tables to make sure it created */
select table_name from user_tables;
