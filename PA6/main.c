#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INGREDIENTS 20 // maximum number of ingredients in a meal
#define MAX_NAME_LENGTH 30 // maximum length of ingredient name
#define CARB_CAL_1G 4	   // Number of calories in 1g carbohydrate 
#define PROTEIN_CAL_1G 4   // Number of calories in 1g protein 
#define FAT_CAL_1G 9	   // Number of calories in 1g fat 
#define WATER_CAL_1G 0	   // Number of calories in 1g water

typedef struct Ingredient Ingredient;

// Structure to represent an ingredient
struct Ingredient{
  char name[MAX_NAME_LENGTH];
  int carbs;
  int protein;
  int fat;
  int water;
  Ingredient *subIngredients;
  int numSubIngredients;
};

// Structure to represent a meal
typedef struct
{
	Ingredient ingredients[MAX_INGREDIENTS]; // array of ingredients in the meal
	int numIngredients;						 // number of ingredients in the meal
	int totalCalories;						 // total number of calories in the meal
	int totalWeight;						 // total weight
	char name[MAX_NAME_LENGTH];				 // name of the meal
} Meal;

void getInput(const char *token, Meal * meal, Ingredient * ing);

int calculateCalories(Ingredient * ingredient);

int main()
{
	Meal * meal; // meal to be created
	meal = malloc(sizeof(Meal) * 1);
	meal->numIngredients = 0;
	meal->totalCalories = 0;

	// Read the name of the meal
	printf("What is the meal?:\n");
	scanf("%s", meal->name);

	// Read ingredients and their properties from the user
	char line[MAX_NAME_LENGTH * MAX_INGREDIENTS]; // input line with all ingredients
	printf("Enter the ingredients of the meal, separated by commas: \n");
	while(!getchar());
	fgets(line, sizeof(line), stdin);

	// Parse ingredients from the input line
	char **tokens = malloc(sizeof(char*)*MAX_NAME_LENGTH);
	for (int i = 0; i < MAX_INGREDIENTS; i++) tokens[i] = malloc(sizeof(char*) * MAX_INGREDIENTS);
	
	char *token = strtok(line, ", ");
	int c = 0;
	while (token != NULL)
	{
		strcpy(tokens[c], token);
		token = strtok(NULL, ", ");//TAKİNG İNGREDİENTS
		c++;
	}
	for (int i = 0; i < c; i++)
	{
		meal->numIngredients++;//
		meal->ingredients[meal->numIngredients - 1].numSubIngredients = 0;
		getInput(tokens[i], meal, &meal->ingredients[meal->numIngredients - 1]);
		meal->totalCalories += calculateCalories(&meal->ingredients[meal->numIngredients - 1]);
	}

	// Print total calories
	printf("Total calories is %d in %dg %s.\n", meal->totalCalories, meal->totalWeight, meal->name);

	free(meal);
	for (int i = 0; i < MAX_NAME_LENGTH; i++) free(tokens[i]);
	free(tokens);
	

	return 0;
}

void getInput(const char *token, Meal * meal, Ingredient * ing){

	char *openParen = strchr(token, '(');//to check numbers
	char *closeParen = strchr(token, ')');

	if (openParen == NULL || closeParen == NULL) {	/*Parantezsiz malzeme gelince onu da ayıracak parantez gelene kadar*/

		char line[MAX_NAME_LENGTH * MAX_INGREDIENTS];

		printf("What is %s?:\n", token);
		fgets(line, sizeof(line), stdin);
		char *tokenNext = strtok(line, ", ");
		int i = 0;
		ing->subIngredients = malloc(sizeof(Ingredient) * MAX_INGREDIENTS);
		while (tokenNext != NULL)
		{
			strcpy(ing->name, token);
			ing->numSubIngredients++;
			getInput(tokenNext, meal, &ing->subIngredients[i]);
			tokenNext = strtok(NULL, ", ");
			i++;
		}
	}
	else{

		char line[MAX_NAME_LENGTH * MAX_INGREDIENTS];

		char * tempToken = malloc(sizeof(char) * MAX_NAME_LENGTH);
		strcpy(tempToken, token);

		char c[10], p[10], f[10];
		char * save1, * save2, * save3;
		float percentC, percentP, percentF;
		int weight;

		printf("List the amount macro nutrients in %s:\n", tempToken);

		fgets(line, sizeof(line), stdin);
		strcpy(c, strtok_r(line, ", ", &save1));//to seperate protein fat and carb
		strcpy(p, strtok_r(line, ", ", &save2));
		strcpy(f, strtok_r(line, ", ", &save3));

		percentC = atof(c+3);
		percentP = atof(p+3);
		percentF = atof(f+3);

		weight = atoi(strstr(tempToken, "(") + 1);		//to find integer in string

		// printf("%s -> %f, %s -> %f, %s -> %f, %d", c, percentC, p, percentP, f, percentF, weight);

		strcpy(ing->name, tempToken);//to calculate weight 
		meal->totalWeight += weight;
		ing->carbs = (percentC/100) * weight;
		ing->protein = (percentC/100) * weight;
		ing->fat = (percentC/100) * weight;
		ing->water = (percentC/100) * weight;
		
	}
}	

int calculateCalories(Ingredient * ingredient) { //To calculate calories

	int temp = 0;

	temp += ingredient->carbs * CARB_CAL_1G;
	temp += ingredient->protein * PROTEIN_CAL_1G;
	temp += ingredient->fat * FAT_CAL_1G;
	temp += ingredient->water * WATER_CAL_1G;

	// printf("\n%d -> %d -> %s\n",ingredient->numSubIngredients, ingredient->carbs, ingredient->name);

	for (int i = 0; i < ingredient->numSubIngredients; i++) {
		temp += calculateCalories(&ingredient->subIngredients[i]);//every ingredients turns one by one
	}

	return temp;
	
}
