#define _CRT_SECURE_NO_WARNINGS  //strcpy함수의 오류를 막기위한 선언
#include "book.h"

/*
	클래스 이름: Library
	기능: Book객체 배열을 이용하여 Book객체들을 관리하고
		  책의 등록, 책들의 목록, 대여된 도서의 정보, 책 대여를 구현한다.
*/

class Library {
private:
	char* library_name;
	Book* book[10];
	int idx;
	int book_sum, page_sum;
public:
	Library(char* name);
	~Library();
	void regist_book(char* book_name, char* writer, int year, int page);
	void print_book_list() const;
	void print_book_statistics() const;
	void rent_book(int num);
};



#define _CRT_SECURE_NO_WARNINGS  //strcpy함수의 오류를 막기위한 선언
#include <iostream>
#include <cstring>
#include "library.h"
#include "book.h"
using namespace std;

/*
	함수 이름: Library
	기능: 도서관의 이름을 등록, 추가 가능한 현재 인덱스 번호/대여된 책의 수/대여된 책의 페이지수 합을 초기화를 한다.
	매개변수: char* name -> 도서관의 이름
*/

Library::Library(char* name)
	: idx(0), book_sum(0), page_sum(0)
{
	int len = strlen(name) + 1;
	library_name = new char[len];
	strcpy(library_name, name);
}

/*
	함수 이름: ~Library
	기능: 도서관의 이름, 동적할당된 책들을 해제한다.
*/

Library::~Library()
{
	delete[]library_name;

	for (int i = 0; i < idx; i++)
		delete book[i];
}

/*
	함수 이름: regist_book
	기능: Book포인터 배열에 책을 등록한다.
	매개변수: char* book_name -> 책의 이름
			  char* writer -> 책의 작성자
			  int year -> 책의 출판년도
			  int page -> 책의 페이지수
*/

void Library::regist_book(char* book_name, char* writer, int year, int page)
{
	book[idx] = new Book(book_name, writer, year, page);
	idx++;
}

/*
	함수 이름: print_book_list
	기능: 도서관에 등록된 책의 목록을 출력한다.
*/

void Library::print_book_list() const
{
	int temp = 0;  // 책의 인덱스를 맞추기 위한 변수

	for (int i = 0; i < idx; i++) {  // 대여된 책의 인덱스는 출력하지 않고 대여되지 않은 책의 인덱스만 출력하기 위한 for루프
		if (book[i]->get_chk()) {
			temp++;
			continue;  // 책의 대여여부가 true이면 continue
		}

		cout << "  " << i + 1 - temp << ") ";
		cout << book[i]->get_book_name() << ", ";
		cout << book[i]->get_writer() << ", ";
		cout << book[i]->get_year() << ", ";
		cout << book[i]->get_page() << "\n";
	}
}

/*
	함수 이름: print_book_statistics
	기능: 도서관에서 대여된 책들의 수와 페이지수 합을 출력한다.
*/

void Library::print_book_statistics() const
{
	cout << "  - 대여 도서 수 : " << book_sum << "\n";
	cout << "  - 대여 도서 페이지 수 합 : " << page_sum << "\n";
}

/*
	함수 이름: rent_book
	기능: 도서관에 등록된 책을 대여한다.
	매개변수: int num -> 대여할 책의 인덱스
*/

void Library::rent_book(int num)
{
	int temp = 0;  // 대여된 책을 빼고 대여 되지 않은 책들의 인덱스를 맞추기 위한 변수

	for (int i = 0; i < num; i++) {  // 대여된 책의 인덱스는 건너뛰고 대여되지 않은 책의 인덱스만 세기 위한 for루프
		if (book[temp]->get_chk())
			i--;

		temp++;
	}

	cout << "  - ";
	cout << book[temp - 1]->get_book_name() << ", ";
	cout << book[temp - 1]->get_writer() << ", ";
	cout << book[temp - 1]->get_year() << ", ";
	cout << book[temp - 1]->get_page() << "\n";

	book_sum++;
	page_sum += book[temp - 1]->get_page();

	book[temp - 1]->set_chk();
}
