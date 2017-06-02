#include "Structs.hpp"

Point::Point( void ): x(0), y(0) {
}

Point::Point( int i, int j ): x(i), y(j) {
}

bool	Point::operator==( Point const & rhs ) {
	return ( this->x == rhs.x && this->y == rhs.y );
}

List::List( void ): content(0), next(0) {
}

List::List( void * data ): content(data), next(0) {
}

void	List::push( List ** head, void * content ) {
	List *	cur;
	List *	elem = new List(content);

	cur = *head;
	if ( cur == 0 )
		*head = elem;
	else {
			while ( cur->next )
				cur = cur->next;
			cur->next = elem;
	}
}

void	List::remove( List ** head, void * content ) {
	List *	prev;
	List *	cur;

	cur = *head;
	prev = cur;
	while ( cur ) {
		if ( cur->content == content ) {
			if ( cur == *head )
				*head = cur->next;
			else
				prev->next = cur->next;
			delete cur;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}

void	List::remove( List * head, void * content ) {
	List *	prev;
	List *	cur;

	cur = head;
	prev = cur;
	while ( cur ) {
		if ( cur->content == content ) {
			if ( cur == head )
				head->content = 0;
			else
				prev->next = cur->next;
			delete cur;
			return;
		}
		prev = cur;
		cur = cur->next;
	}
}
