#include <cstdio>
#include <cstring>
#include <string>
#include <cctype>
#include <cmath>
#include <cstdlib>
#include <clocale>
#include <utility>
using namespace std;

class Dstr
{
	private:
		char **str;
		int stramount;
	public:
	
		//конструктор
		Dstr()
		{
			stramount = 0;
			printf("The main object is created\n");
		}
		
		//конструктор копирование
		Dstr(const Dstr &str_obj)
		{
			stramount = str_obj.stramount;
			for(int stramount_i = 0; stramount_i < stramount; stramount_i++)
			{
				
				if(stramount_i == 0)
				{
					if((str = (char **)malloc(sizeof(char *))) == NULL)
					{
						printf("malloc error\n");
						return;
					}
				}
				else
				{
					if((str = (char **)realloc(str,((stramount_i + 1) * sizeof(char *)))) == NULL)
					{
						printf("realloc error\n");
						return;
					}
				}
				
				if((str[stramount_i] = (char *)malloc((strlen(str_obj.str[stramount_i]) + 1) * sizeof(char))) == NULL)
				{
					
					printf("malloc error\n");
					return;
				}
				strcpy(str[stramount_i],str_obj.str[stramount_i]);
			}
			printf("Copy of the object is created\n");
			return;
		}
		
		//деструктор
		~Dstr()
		{
			for(int i1 = (stramount - 1); i1 >= 0; i1--)free(str[i1]);
			printf("Object deleted\n");
		}
		
		//оператор присваивания
		Dstr& operator= (const Dstr &str_obj_copy)
		{
			stramount = str_obj_copy.stramount;
			for(int stramount_i = 0; stramount_i < stramount; stramount_i++)
			{
				
				if(stramount_i == 0)
				{
					if((str = (char **)malloc(sizeof(char *))) == NULL)
					{
						printf("malloc error\n");
						return *this;
					}
				}
				else
				{
					if((str = (char **)realloc(str,((stramount_i + 1) * sizeof(char *)))) == NULL)
					{
						printf("realloc error\n");
						return *this;
					}
				}
				
				if((str[stramount_i] = (char *)malloc((strlen(str_obj_copy.str[stramount_i]) + 1) * sizeof(char))) == NULL)
				{
					
					printf("malloc error\n");
					return *this;
				}
				strcpy(str[stramount_i],str_obj_copy.str[stramount_i]);
			}
			printf("The copy is assigned the original\n");
			return *this;
		}
		
		//перемещение
		Dstr move(const Dstr &str_obj_copy)
		{
			stramount = std::move(str_obj_copy.stramount);
			for(int stramount_i = 0; stramount_i < stramount; stramount_i++)
			{
				
				if(stramount_i == 0)
				{
					if((str = (char **)malloc(sizeof(char *))) == NULL)
					{
						printf("malloc error\n");
						return *this;
					}
				}
				else
				{
					if((str = (char **)realloc(str,((stramount_i + 1) * sizeof(char *)))) == NULL)
					{
						printf("realloc error\n");
						return *this;
					}
				}
				
				if((str[stramount_i] = (char *)malloc((strlen(str_obj_copy.str[stramount_i]) + 1) * sizeof(char))) == NULL)
				{
					
					printf("malloc error\n");
					return *this;
				}
				str[stramount_i] = std::move(str_obj_copy.str[stramount_i]);
			}
			printf("Object relocated\n");
			return *this;
		}
		
		//ввод строки
		void setstring()
		{
			char inpchar;
			printf("Enter the string: ");
			fflush(stdin);
			scanf("%c",&inpchar);
			int strlen = 0;
			while(inpchar != 10)
			{
				
				if(strlen == 0)
				{
					if(stramount == 0)
					{
						if((str = (char **)malloc(sizeof(char *))) == NULL)
						{
							printf("malloc error\n");
							return;
						}
					}
					else
					{
						if((str = (char **)realloc(str,((stramount + 1) * sizeof(char *)))) == NULL)
						{
							printf("realloc error\n");
							return;
						}
					}
					
					if((str[stramount] = (char *)malloc(sizeof(char))) == NULL)
					{
						
						printf("malloc error\n");
						return;
					}
				}
				
				if((str[stramount] = (char *)realloc(str[stramount],((strlen + 1) * sizeof(char)))) == NULL)
				{
					printf("realloc error\n");
					return;
				}
				str[stramount][strlen] = inpchar;
				strlen++;
				scanf("%c",&inpchar);
			}
			
			if((str[stramount] = (char *)realloc(str[stramount],((strlen + 1) * sizeof(char)))) == NULL)//???((strlen + 1) + sizeof(char))
			{
				printf("realloc error\n");
				return;
			}
			str[stramount][strlen] = '\0';
			stramount++;
			printf("String added\n");
			return;
		}
		
		//вывод строк
		void getstrings()
		{
			if(stramount != 0)
			{
				printf("Entered strings:\nNumber\tString\n");
				for(int i = 0; i < stramount; i++)printf("%i\t%s\n",(i + 1), str[i]);
			}
			else printf("No entered strings\n");
			return;
		}
		
		//сложение строк
		void add()
		{
			if(stramount > 1)
			{
				int to_str,from_str;
				
				do
				{
					printf("Enter the destination string number[1-%i]: ",stramount);
					fflush(stdin);
					scanf("%i",&to_str);
				}
				while((to_str < 1)||(to_str > stramount));
				
				if((to_str != 1)&&(to_str != stramount))
				{
					do
					{
						if((to_str == 2)||(to_str == (stramount - 1)))
						{
							if(to_str == 2)printf("Enter the departure string number[1,%i-%i]: ",(to_str + 1),stramount);
							else printf("Enter the departure string number[1-%i,%i]: ",(to_str - 1),stramount);
						}
						else printf("Enter the departure string number[1-%i,%i-%i]: ",(to_str - 1),(to_str + 1),stramount);
						fflush(stdin);
						scanf("%i",&from_str);
					}
					while((from_str < 1)||(from_str == to_str)||(from_str > stramount));
				}
				else
				{
					if(to_str == 1)
					{
						if(stramount == 2)
						{
							printf("String number of departure = 2\n");
							from_str = 2;
						}
						else
						{
							do
							{
								printf("Enter the departure string number[2-%i]: ",stramount);
								fflush(stdin);
								scanf("%i",&from_str);
							}
							while((from_str < 2)||(from_str > stramount));
						}
					}
					else
					{
						if(stramount == 2)
						{
							printf("String number of departure = 1\n");
							from_str = 1;
						}
						else
						{
							do
							{
								printf("Enter the departure string number[1-%i]: ",stramount-1);
								fflush(stdin);
								scanf("%i",&from_str);
							}
							while((from_str < 1)||(from_str > (stramount - 1)));
						}
					}
				}
				
				to_str--;
				from_str--;
				if((str[to_str] = (char *)realloc(str[to_str],((strlen(str[to_str]) + strlen(str[from_str]) + 1) * sizeof(char)))) == NULL)
				{
					printf("realloc error\n");
					return;
				}
				strcat(str[to_str],str[from_str]);
				printf("String %i added to string %i\n",(from_str + 1),(to_str + 1));
				return;
			}
			else printf("Requires 2 entered strings \n");
			return;
		}
		//обратная лексикографическая сортировка с использованием STL
		void revleksosort(Dstr str_obj_copy)
		{
			if(str_obj_copy.stramount != 0)
			{
				string stlmaxstr,stltempstr;
				for(int stramount_i = 0; stramount_i < str_obj_copy.stramount; stramount_i++)for(int strlen_i = 0; strlen_i < int(strlen(str_obj_copy.str[stramount_i])); strlen_i++)
					str_obj_copy.str[stramount_i][strlen_i] = tolower(str_obj_copy.str[stramount_i][strlen_i]);
				
				for(int stramount_i1 = 0; stramount_i1 < str_obj_copy.stramount; stramount_i1++)
				{
					stlmaxstr.insert(0, str_obj_copy.str[stramount_i1]);
					stlmaxstr.push_back('\0');
					for(int stramount_i2 = stramount_i1; stramount_i2 < str_obj_copy.stramount; stramount_i2++)
					{
						stltempstr.insert(0,str_obj_copy.str[stramount_i2]);
						stltempstr.push_back('\0');
						
						if(stlmaxstr < stltempstr)
						{
							if((str[stramount_i1] = (char *)realloc(str[stramount_i1],((stltempstr.size() + 1) * sizeof(char)))) == NULL)
							{
								printf("realloc error\n");
								return;
							}
							
							for(int strlen_i = 0; strlen_i < int(stltempstr.size()); strlen_i++)str_obj_copy.str[stramount_i1][strlen_i] = stltempstr[strlen_i];
							
							str_obj_copy.str[stramount_i1][strlen(str_obj_copy.str[stramount_i1]) + 1] = '\0';
							
							if((str[stramount_i2] = (char *)realloc(str[stramount_i2],((stlmaxstr.size() + 1) * sizeof(char)))) == NULL)
							{
								printf("realloc error\n");
								return;
							
							}
							for(int strlen_i = 0; strlen_i < int(stlmaxstr.size()); strlen_i++)str_obj_copy.str[stramount_i2][strlen_i] = stlmaxstr[strlen_i];
							
							str_obj_copy.str[stramount_i2][strlen(str_obj_copy.str[stramount_i2]) + 1] = '\0';
							stlmaxstr.clear();
							stlmaxstr.insert(0,stltempstr);
							stlmaxstr.push_back('\0');
						}
						
						stltempstr.clear();
					}
					stlmaxstr.clear();
				}
				printf("Number\tString\n");
				
				for(int stramount_i = 0; stramount_i < str_obj_copy.stramount; stramount_i++)printf("%i\t%s\n",(stramount_i + 1),str_obj_copy.str[stramount_i]);
			}
			else printf("No entered string\n");
			return;
		}
};

int main()
{
	Dstr str_obj;
	printf("Available commands:\n\t'a' - Entering string\n\t's' - Show all strings\n\t'c' - Creating a copy of the object and work with it\n\t'+' - Addition of two strings\n");
	printf("\t'l' - Reverse lexicographic sorting\n\t'0' - Exit\n");
	printf("Assigning and moving an object is available from the work menu with a copy of the object.\n");
	char com;
	do
	{
		printf("Command(str_obj): ");
		fflush(stdin);
		scanf("%c",&com);
		switch(com)
		{
			case('a'):str_obj.setstring();break;
			case('s'):str_obj.getstrings();break;
			case('c'):
			{
				Dstr str_obj_copy=str_obj;
				printf("Available commands:\n\t'a' - Entering string\n\t's' - Show all strings\n\t'm' - Moving a copy to the original object(copy will be deleted) \n");
				printf("\t'+' - Addition of two strings\n\t'=' - Assign a copy of the object to the original\n\t'l' - Reverse lexicographic sorting\n\t'0' - Exit and delete copy\n");
				do
				{
					printf("Command(str_obj_copy): ");
					fflush(stdin);
					scanf("%c",&com);
					switch(com)
					{
						case('a'):str_obj_copy.setstring();break;
						case('s'):str_obj_copy.getstrings();break;
						case('m'):
						{
							str_obj.move(str_obj_copy);
							com='0';
							break;
						}
						case('+'):str_obj_copy.add();break;
						case('='):str_obj=str_obj_copy;break;
						case('l'):str_obj_copy.revleksosort(str_obj_copy);
					}
				}
				while(com != '0');
				printf("Available commands:\n\t'a' - Entering string\n\t's' - Show all strings\n\t'c' - Creating a copy of the object and work with it\n\t'+' - Addition of two strings\n");
				printf("\t'l' - Reverse lexicographic sorting\n\t'0' - Exit\n");
				com = ' ';
				break;
			}
			case('+'):str_obj.add();break;
			case('l'):str_obj.revleksosort(str_obj);
			case('0'):break;
		}
	}
	while(com != '0');
}