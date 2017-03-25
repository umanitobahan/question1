#ifndef _TABLE_H
#define _TABLE_H
	
	typedef enum BOOL { false, true } Boolean;	
	int size();
	Boolean insert(char const * const new_string);
	Boolean delete(char const * const target);
	Boolean search(char const * const target);
	char * firstItem();
	char * nextItem();
	

#endif
