/**
 * @file course.h
 * @author Sharmin Ahmed
 * @date 2022-04-10
 * @brief course library for managing courses, including course type definition 
 *        and course functions including enrolling students, printing courses, 
 *        calculating top student.
 *
 */


#include "student.h"
#include <stdbool.h>

/** 
 * Course type stores a course with fields name, code, students, and total_students. 
 * 
 */ 
typedef struct _course 
{
  char name[100]; /**< Course's name */
  char code[10]; /**< Course's code */
  Student *students; /**< Course's students */
  int total_students; /**< Number of students */
} Course;

void enroll_student(Course *course, Student *student);
void print_course(Course *course);
Student *top_student(Course* course);
Student *passing(Course* course, int *total_passing);


