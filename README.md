ContactSystemSimplify
===================================
This project is about how to make a simple address book system

## 1.Introduction

* 1.1 The following code introduces the members of person that in address book:
```cpp
typedef struct Person
{
  string Name;
  char Gender;
  int Age;
  string TelNumber;
  int Score;
} PERSON;
```

* 1.2 The following code defines the structure of the address book:
```cpp
typedef struct ContactData
{
  PERSON person[PERSONNUMBER];
  int curPersonNumber;
} ADDATA;
```
  
`curPersonNumber` Indicates the number of people recorded in the current address book.
* 1.3 The following code defines maxperson in address book.
```cpp
#define PERSONNUMBER 100
```
