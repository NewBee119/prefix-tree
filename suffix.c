#include"suffix.h"










//build a tree

PNode Build_tree(char* path, int reverse)

{

	FILE*fp = NULL;

	char buff[1024] = { "\0" };

	int i;

	PNode root;

	int size_t;



	//create empty Tree

	root = CreateNullTree();



	//Žò¿ªÎÄŒþ

	fp = fopen(path, "r");

	while (fgets(buff, 1024, fp))

	{

		//for (i = 0; i < n;i++)



		//this is the head of this document

		if (buff[0] == '[')

		{

			continue;

		}



		if (buff[0] == '\r' || buff[0] == '\n')

		{

			continue;

		}

		size_t = standard_and_size(buff);
		if (reverse == 1)
		{
			
			Inversion(buff,size_t);
		}

		

		Insert_Leaf(buff, root, root);

	}

	return root;



}





int Insert_Leaf(char*Pstr, PNode root, PNode father)

{

	//if root == father it means that it is root





	if (root == father)

	{

		if (root->child == NULL)

		{

			root->child = (struct Node*)malloc(sizeof(struct Node));

			root->child->key = NULL;

			root->child->child = NULL;

			root->child->brother = NULL;

			root->flag = 0;

		}



		Insert_Leaf(Pstr, root->child, root);

	}

	else

	{

		if (root->key == NULL)

		{

			root->key = Pstr[0];

			Pstr = Pstr + 1;

			if (Pstr[0] == '\0')

			{

				root->flag = 1;

				return 1;

			}

			if (root->child == NULL)

			{

				root->child = (struct Node*)malloc(sizeof(struct Node));

				root->child->key = NULL;

				root->child->child = NULL;

				root->child->brother = NULL;

				root->child->flag = 0;

			}

			Insert_Leaf(Pstr, root->child, root);

		}

		else{

			if (root->key == Pstr[0])

			{

				Pstr = Pstr + 1;
				if (Pstr[0] == '\0')
				{
					root->flag = 1;
					return 1;
				}

				if (root->child == NULL)

				{

					root->child = (struct Node*)malloc(sizeof(struct Node));

					root->child->key = NULL;

					root->child->child = NULL;

					root->child->brother = NULL;

					root->child->flag = 0;

				}

				Insert_Leaf(Pstr, root->child, root);

			}

			else

			{

				if (root->brother == NULL)

				{

					root->brother = (struct Node*)malloc(sizeof(struct Node));

					root->brother->key = NULL;

					root->brother->child = NULL;

					root->brother->brother = NULL;

					root->brother->flag = 0;

				}

				Insert_Leaf(Pstr, root->brother, root);

			}

		}

	}

}





//Create a empty tree

PNode CreateNullTree()

{

	PNode root = NULL;

	root = (struct Node*)malloc(sizeof(struct Node));

	root->key = NULL;

	root->brother = NULL;

	root->child = NULL;

	root->flag = 0;

	return root;

}


int standard_and_size(char*Pstr)
{
	int i = 0;

	char temp;

	int size_t = 0;

	while (1)

	{



		if (Pstr[i] != '\0'&& Pstr[size_t] != '\r' && Pstr[size_t] != '\n')

		{

			size_t++;

			i++;

		}

		else

		{

			break;

		}
		

	}
	if (Pstr[size_t] == '\r' || Pstr[size_t] == '\n')

	{

		Pstr[size_t] = '\0';

	}
	
	return size_t;
}


//

char* Inversion(char*Pstr,int size_t)

{

	int i = 0;

	char temp;


	
	for (i = 0; i < size_t / 2; i++)

	{

		temp = Pstr[i];

		Pstr[i] = Pstr[size_t - i - 1];

		Pstr[size_t - i - 1] = temp;

	}

	return Pstr;

}



int Search_Tree(char*Pstr, PNode root, PNode father,int complete,int reverse)

{

	int size_t;
	// invert the string



	

	







	if (root == father&&reverse == 1)

	{
		size_t = standard_and_size(Pstr);
		Inversion(Pstr,size_t);

	}

	
	if (root == father)

	{

		if (root->child != NULL)

		{

			return Search_Tree(Pstr, root->child, root, complete, reverse);

		}

		else

		{

			printf("it is empty tree");

			return 0;

		}



	}

	else

	{

		if (Pstr[0] == root->key)

		{

			Pstr = Pstr + 1;

			if (Pstr[0] != '\0')

			{

				if (root->flag == 1)
				{
					if (complete == 1)
					{
							
						if (root->child!=NULL)
						{
							return Search_Tree(Pstr, root->child, root, complete, reverse);
						}
						else
						{
							return 1;
						}
								

					}
					else
					{
						return 1;
					}
				
				}

				if (root->child == NULL)

				{

					return 0;

				}

				else

				{

					return Search_Tree(Pstr, root->child, root, complete, reverse);

				}



			}

			else
			{
				if (root->flag == 1)
				{
					return 1;
				}
					
				else
				{
					return 0;
				}

			}

		}

		else

		{

			if (root->brother == NULL)

			{

				return 0;

			}

			else

			{

				return Search_Tree(Pstr, root->brother, root, complete, reverse);

			}

		}

	}
}

PNode Print_Tree(PNode root, PNode father, char *buff, int num, int reverse)
{
	//to judge the root is the root of tree
	int i;
	int size_t;
	if (root == father)
	{
		buff = (char*)malloc(1024 * sizeof(char));
		memset(buff, '\0', 1024);
		Print_Tree(root->child, root, buff, 0, reverse);
	}
	else
	{
		buff[num] = root->key;
		num = num + 1;
		if (root->flag != 1)
		{
			Print_Tree(root->child, root, buff, num, reverse);
		}
		else
		{
			size_t = standard_and_size(buff);
			if (reverse == 1)
			{
				Inversion(buff,size_t);
				printf(buff);
				Inversion(buff, size_t);
				printf("\r\n");
			}
			else
			{
				printf(buff);
				printf("\r\n");
			}
			
			if (root->child != NULL)
			{
				Print_Tree(root->child, root, buff, num, reverse);
			}
			
		}
		if (root->brother != NULL)
		{
			memset(buff + num-1, '\0', 1024 - num);
			Print_Tree(root->brother, root, buff, num - 1, reverse);
		}
		else
		{
			return 1;
		}
		
		
	}
}

int strandstr(char *path,char *str)

{

	int i;
	int length = 0;

	FILE *fp = NULL;

	char strline[128];



	memset(strline, 0x0, sizeof(strline));



	fp = fopen(path, "r");

	if (!fp)

		return 0;



	while (fgets(strline, 128, fp))

	{
		for (i = 0; i < strlen(strline); i++)
		{
			if (strline[i] == '\r' || strline[i] == '\n')
			{
				strline[i] = '\0';
			}		
		}
			
		length = strlen(strline);

		if (strlen(strline) <= 2)

		{

			memset(strline, 0x0, sizeof(strline));

			continue;

		}
		if (strcmp(str, strline)==0)
		{
				fclose(fp);
				return 1;
		
			   
		}
			
	}
	
fclose(fp);
return 0;
}


