/**
 * @file course.c
 * @author Sharmin Ahmed
 * @date 2022-04-10
 * @brief course library for managing courses, including course type definition 
 *        and course functions including enrolling students, printing courses, 
 *        calculating top student.
 *
 */

#include "course.h"
#include <stdlib.h>
#include <stdio.h>

/** 
 * Enrolls a student into a course
 * @param course a pointer to the course a student is going to be enrolled in
 * @param student a pointer to the student who is being enrolled into the course
 * @return nothing
 */ 
void enroll_student(Course *course, Student *student)
{
  course->total_students++;

  // If it is the first student being enrolled in the class then allocate space for one student 
  // else use realloc to reallocate the previous space by the new space which has additional space for 
  // one more student
  if (course->total_students == 1) 
  {
    course->students = calloc(1, sizeof(Student));
  }
  else 
  {
    course->students = 
      realloc(course->students, course->total_students * sizeof(Student)); 
  }

  // set the new emoty space created to the new student. 
  course->students[course->total_students - 1] = *student;
}

/** 
 * prints a course's information such as course name, course code, total students, and all students
 * @param course a pointer to the course which is being printed
 * @return nothing
 */ 
void print_course(Course* course)
{
  printf("Name: %s\n", course->name);
  printf("Code: %s\n", course->code);
  printf("Total students: %d\n\n", course->total_students);
  printf("****************************************\n\n");

  // loop through each student and print
  for (int i = 0; i < course->total_students; i++) 
    print_student(&course->students[i]);
}

/** 
 * Calculates the student with the highest average by looping through each student and calculating their average.
 * @param course a pointer to the course
 * @return a student pointer who has the highest average
 * 
 */ 
Student* top_student(Course* course)
{
  if (course->total_students == 0) return NULL;
 
  double student_average = 0;
  double max_average = average(&course->students[0]);
  Student *student = &course->students[0];
 
  // loop through all students and check if they have a higher avg then the max_avg,
  // if they do, set it as the max_average and continue on to the next student. 
  for (int i = 1; i < course->total_students; i++)
  {
    student_average = average(&course->students[i]);
    if (student_average > max_average) 
    {
      max_average = student_average;
      student = &course->students[i];
    }   
  }

  return student;
}

/** 
 * Calculates the number of students and which students are passing in a certain course.
 * @param course a pointer to the course.
 * @param total_passing an int pointer to store the total number of students passing the course.
 * @return A pointer to an array of type student which contains the list of students passing the course
 */ 
Student *passing(Course* course, int *total_passing)
{
  int count = 0;
  Student *passing = NULL;
  
  // loops through all students in the course and increases counter if their 
  // avg grade is above or equal to 50. 
  for (int i = 0; i < course->total_students; i++) 
    if (average(&course->students[i]) >= 50) count++;
  

  passing = calloc(count, sizeof(Student));

  // loops through all students and adds their name to passing array if their grade is above or equal to 50.
  int j = 0;
  for (int i = 0; i < course->total_students; i++)
  {
    if (average(&course->students[i]) >= 50)
    {
      passing[j] = course->students[i];
      j++; 
    }
  }

  *total_passing = count;

  return passing;
}