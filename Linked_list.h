#ifndef  _LINKED_LIST

#define _LINKED_LIST


// User-defined datatypes
typedef struct my_student
{
    char std_name[50];
    unsigned int std_birth_day;
    unsigned int std_birth_month;
    unsigned int std_birth_year;
    unsigned int std_ID;
    char std_address[50];
    unsigned int std_number;
    float std_score [6];
    float std_cum_score;

    struct my_student * next_node;
}student;


// linked list header
typedef struct my_Linked_list
{
    student * list_head;
    unsigned int list_size;
}linked_list;

typedef enum my_std_return
{
    list_not_exist,
    list_created_successfully,
    list_not_created,
    list_empty,
    node_created,
    node_not_created,
    std_deleted,
    std_not_found,
    ok
}std_return;

//functions Prototypes
std_return create_list(linked_list *const ls);
std_return insert_node ( linked_list *const ls);
std_return view_list ( const linked_list * ls , const char sort_type);
std_return delete_student ( linked_list *const ls , const unsigned int std_ID);
std_return std_score(const linked_list *const ls , const unsigned int std_ID);
std_return std_edit(const linked_list *const ls , const unsigned int std_ID);
std_return std_info_all(const linked_list * ls);

void sorted_names(const linked_list * ls); // function for debugging

#endif // _LINKED_LIST
