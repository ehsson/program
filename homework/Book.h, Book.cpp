#define _CRT_SECURE_NO_WARNINGS  //strcpy함수의 오류를 막기위한 선언

/*
	클래스 이름: Book
	기능: 책의 이름, 작성자, 출판년도, 페이지 수, 대여여부를 관리하고
		  위의 내용들을 반환하는 기능을 구현한다.
*/

class Book {
private:
	char* book_name;
	char* writer;
	int year;
	int page;
	bool chk;
public:
	Book(char* book_name, char* wirter, int year, int page);
	~Book();
	char* get_book_name() const;
	char* get_writer() const;
	int get_year() const;
	int get_page() const;
	void set_chk();
	bool get_chk() const;
};



#define _CRT_SECURE_NO_WARNINGS  //strcpy함수의 오류를 막기위한 선언
#include <iostream>
#include <cstring>
#include "book.h"
using namespace std;

/*
	함수 이름: Book
	기능: 책의 정보를 입력받는다.
	매개변수: char* book_name -> 책의 이름
			  char* writer -> 책의 작성자
			  int year -> 책의 출판년도
			  int page -> 책의 페이지 수
*/

Book::Book(char* book_name, char* writer, int year, int page)
	:year(year), page(page), chk(false)
{
	int len = strlen(book_name) + 1;
	this->book_name = new char[len];
	strcpy(this->book_name, book_name);

	len = strlen(writer) + 1;
	this->writer = new char[len];
	strcpy(this->writer, writer);
}

/*
	함수 이름: ~Book
	기능: 동적할당된 책의 이름과 작성자를 동적할당을 해제시킨다.
*/

Book::~Book()
{
	delete[]book_name;
	delete[]writer;
}

/*
	함수 이름: get_book_name
	기능: 책의 이름을 반환한다.
	반환값: 책의 이름
*/

char* Book::get_book_name() const
{
	return book_name;
}

/*
	함수 이름: get_writer
	기능: 책의 작성자를 반환한다.
	반환값: 책의 작성자
*/

char* Book::get_writer() const
{
	return writer;
}

/*
	함수 이름: get_year
	기능: 책의 출판년도를 반환한다.
	반환값: 책의 출판년도
*/

int Book::get_year() const
{
	return year;
}

/*
	함수 이름: get_page
	기능: 책의 페이지수를 반환한다.
	반환값: 책의 페이지수
*/

int Book::get_page() const
{
	return page;
}

/*
	함수 이름: set_chk
	기능: 책의 대여여부를 true로 바꿔준다.
*/

void Book::set_chk()
{
	chk = true;
}

/*
	함수 이름: get_chk
	기능: 책의 대여여부를 반환한다.
	반환값: 책의 대여여부
*/

bool Book::get_chk() const
{
	return chk;
}
