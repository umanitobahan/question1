#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "table.h"

static Boolean result = false;
static int nodes = 0;
static int inserts = 0;
static int find = 0;
static int testsExecuted = 0;
static int deletes = 0;
static char *item = NULL;
static void testInsert();
static void testSearch();
static void testDelete();

int main(int argc, char *argv[]){
		

	printf("Test insert----------------------------------\n\n");
	char *string1 = "cat";
	result = insert(string1);
	testInsert();
	char *string2 = "dog";
	result = insert(string2);
	testInsert();
	char *string3 = "";
	char *string4 = "         ";
	char *string5 = "kkkk";
	result = insert(string3);
	testInsert();
	result = insert(string4);
	testInsert();
	result = insert(string5);
	testInsert();
	char *string6 = "                                    ";
	char *string7 = "batman";
	char *string8 = "batmanbaby";
	result = insert(string6);
	testInsert();
	result = insert(string7);
	testInsert();
	result = insert(string8);
	testInsert();

	nodes = size();
	printf("insert %d strings\nThere are %d nodes in the list\n\n\n", inserts, nodes);

	printf("Test travel the list---------------------------\n");
	item = firstItem();
	printf("%s\n", item);
	while(item != NULL){
		item = nextItem();
		if(item != NULL)
			printf("%s\n",item);
	}
	nodes = size();
	printf("%d item was printed\n", nodes);
	printf("\n\n");
	
	printf("Test search---------------------------------\n\n");

	char *search1 = "cat";
	result = search(search1);
	testSearch();
	char *search2 = "superman";
	char *search3 = "batmanbaby";
	char *search4 = "string3";
	char *search5 = "...................";
	char *search6 = "";
	char *search7 = "kkkk";
	char *search8 = "bbbb";
	result = search(search2);
	testSearch();
	result = search(search3);
	testSearch();
	result = search(search4);
	testSearch();
	result = search(search5);
	testSearch();
	result = search(search6);
	testSearch();
	result = search(search7);
	testSearch();
	result = search(search8);
	testSearch();
		
	
	printf("Totally searched %d items\n", testsExecuted);
	printf("find %d items in the list\n", find);	
	printf("\n\nDelete some items\n\n");
	testsExecuted = 0;
	char *dstring1 = "batman";
	char *dstring2 = "betman";
	char *dstring3 = "";
	char *dstring4 = "            ";
	char *dstring5 = "cat";
	char *dstring6 = "dog";
	char *dstring7 = "dogs";
	char *dstring8 = string8;
	result = delete(dstring1);
	testDelete();
	result = delete(dstring2);
	testDelete();
	result = delete(dstring3);
	testDelete();
	result = delete(dstring4);
	testDelete();
	result = delete(dstring5);
	testDelete();
	result = delete(dstring6);
	testDelete();
	result = delete(dstring7);
	testDelete();
	result = delete(dstring8);
	testDelete();
	
	printf("Delete %d items\n", deletes);
	printf("%d items executed\n\n", testsExecuted);
	
	printf("Print the list after deleted-------------\n\n");
	item = firstItem();
        printf("%s\n", item);
        while(item != NULL){
                item = nextItem();
                if(item != NULL)
                        printf("%s\n",item);
        }
        nodes = size();
        printf("%d item was printed\n", nodes);
        
	return EXIT_SUCCESS;
}

static void testInsert(){
	if(result){
		inserts++;
	}
	else{
		printf("string insert fail!!!!\n");
	}

	result = false;
}

static void testSearch(){
        if(result){
		find++;
	}
	else{
	}
	result = false;	
	testsExecuted++;
}

static void testDelete(){
	if(result){
		deletes++;
	}
	else{
	}
	result = false;
	testsExecuted++;
}
