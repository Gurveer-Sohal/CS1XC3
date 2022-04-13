/**
 * @file student.h
 * @author Sharmin Ahmed
 * @date 2022-04-10
 * @brief Student library for managing students, including student type definition 
 *        and student functions.
 *
 */



/** 
 * Student type stores a student with fields first name, last name, id, grades array, and number of grades. 
 *
 */ 
typedef struct _student 
{ 
  char first_name[50]; /**< student's first name stored as a character array of length 50 */ 
  char last_name[50]; /**< student's last name stored as a character array of length 50 */
  char id[11]; /**< student's id stored as a character array of  length 11 */
  double *grades; /**< student's grades stored as a pointer to an array of type double */
  int num_grades; /**< Number of grades the student has, stored as an int */
} Student;

 
// function declaration 
void add_grade(Student *student, double grade);
double average(Student *student);
void print_student(Student *student);
Student* generate_random_student(int grades); 
