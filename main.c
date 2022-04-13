/**
 * @mainpage Course function demonstration
 *  
 * The course function demonstration shows how multiple functions in the course 
 * library work, including:
 * - creating a course
 * - enrolling students
 * - printing a course
 * - printing students who are passing the course
 * 
 * @file main.c
 * @author Sharmin Ahmed
 * @date 2022-04-10 
 * @brief Run demonstration code for the course library methods.
 * 
 */ 


#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "time.h"
#include "course.h"

int main()
{
  
  srand((unsigned) time(NULL));

  // creates a course, gives it a name and course code
  Course *MATH101 = calloc(1, sizeof(Course));
  strcpy(MATH101->name, "Basics of Mathematics");
  strcpy(MATH101->code, "MATH 101");

  // generate 20 random students and enrolls them into the course. 
  for (int i = 0; i < 20; i++) 
    enroll_student(MATH101, generate_random_student(8));
  

  print_course(MATH101);

  // demonstrate the top_student function
  Student *student;
  student = top_student(MATH101);
  printf("\n\nTop student: \n\n");
  print_student(student);

  // demonstrates the passing function 
  int total_passing;
  Student *passing_students = passing(MATH101, &total_passing);
  printf("\nTotal passing: %d\n", total_passing);
  printf("\nPassing students:\n\n");
  for (int i = 0; i < total_passing; i++) print_student(&passing_students[i]);
  
  return 0;
}