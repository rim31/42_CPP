#ifndef POINT_H
# define POINT_H

struct Point {
	int	x;
	int	y;

	Point( void );
	Point( int x, int y );

	bool	operator==( Point const & rhs );
};

struct List {
	void *	content;
	List *	next;

	List( void );
	List( void * content );

	void	push( List ** head, void * content );
	void	remove( List ** head, void * content );
	void	remove( List * head, void * content );
};

#endif
