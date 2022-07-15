#include<stdio.h>
#include<string.h>

//Declaring the Functions//

int new();
int view();           

int main()
{

    int choice,select;
    do
    {
        printf("\t\t\t  .....................................................\n");
        printf("\t\t\t\t   Welcome to the Cricket Score Sheet\n\n");
        printf("\t\t\t\t   Main Menu :-\n");
        printf("\t\t\t\t   1.Create New Score Sheet\n");
        printf("\t\t\t\t   2.View Scores \n");
        printf("\t\t\t\t   3.Exit from the program\n\n");
		
		printf("Enter your choice : ");
        scanf("%d",&choice);
		
		if(choice==1)
		new();
		
		else if(choice==2)
        view();
        
		else if(choice==3)
        printf("You are Exited from the Program\n");
        
        else
        printf("Invalid Entry\n");
        
        printf("\nIf You Want to start the Program Again : If Yes Press 1 : ");
        scanf("%d",&select);
        
    } while(select==1);     						//The Entire Program Repeats if 1 is Opted....!!!
    
    printf("THANK YOU :) \n");
    
}
   
//Declaring Structure Variables // 

struct new                   
{
    char name[100],venue[100];
    char t1name[100], t2name[100];
    char amorpm[2];
    int tosswinner, score1, score2, overs;
    int w1,w2,t;
    int hour, min;
    int flag, date, month, year;
    float over1, over2;
    
}n1;

int new()
{
	FILE *fp;           														          //Declaring File Pointer 
    do
    {
    	fflush(stdin);
    	
        printf("Enter the name of the Match : ");
        gets(n1.name);
        fflush(stdin);
    
        printf("Enter the Venue of the Match Held at : ");
        gets(n1.venue);
        fflush(stdin);
	
		
		printf("\nEnter the Teams going to play match  :\n");
        printf("Team 1: ");
        gets(n1.t1name);
        fflush(stdin);
        
        printf("Team 2: ");
        gets(n1.t2name);
        fflush(stdin);
        
		printf("\nEnter the Date(in DD-MM-YYYY): ");
        scanf("%d-%d-%d",&n1.date,&n1.month,&n1.year);
        
		printf("Enter the time of the match held (Hours:Minutes:am or pm): ");         //Time...!!!
        scanf("%d:%d:%s",&n1.hour,&n1.min,n1.amorpm);
		
		printf("\nEnter the Toss Winner ( 1-%s (or) 2-%s ) : ",n1.t1name,n1.t2name);
        scanf("%d",&n1.tosswinner);
		
		printf("Enter Total Overs Of the Match : ");
        scanf("%d",&n1.overs); 
		 
		printf("\n"); 
		
		printf("Which Team is Batting First ( 1-%s (or) 2-%s ) : ",n1.t1name,n1.t2name);
		scanf("%d",&n1.t); 
        
		if(n1.t==1)
        {
            printf("Enter %s Score : ",n1.t1name);
            scanf("%d",&n1.score1);
            printf("Enter %s Score : ",n1.t2name);     //If team 1 Bats 1st
            scanf("%d",&n1.score2);                            
        }
        
		else if(n1.t==2)
        {
            printf("Enter %s Score :",n1.t2name);
            scanf("%d",&n1.score2);
            printf("Enter %s Score :",n1.t1name);
            scanf("%d",&n1.score1);                       //If Team 2 Bats First
        }
        printf("\n");
		
		printf("Enter the overs at which they have scored : \n");
        printf("%s Overs Of Scoring  : ",n1.t1name);
        scanf("%f",&n1.over1);
        
        while(n1.over1 > n1.overs || n1.over1 <= 0)
        {
        printf("\nINVALID OVERS ENTER VALID OVERS\n");
        printf("%s Overs Of Scoring  : ",n1.t1name);
        scanf("%f",&n1.over1);
        }                                                                //Scanning Overs 
        
		printf("%s Overs Of Scoring  : ",n1.t2name);
        scanf("%f",&n1.over2);
		
		while(n1.over2 > n1.overs || n1.over2 <= 0)
        {
            printf("\nINVALID OVERS ENTER VALID OVERS\n");
            printf("%s Overs Of Scoring  : ",n1.t2name);
            scanf("%f",&n1.over2);
        }
        
        printf("\nEnter the wickets of %s : ",n1.t1name);
        scanf("%d",&n1.w1);
        
        while(n1.w1<0 || n1.w1>10)
        {
            printf("\nInvalid Number of wickets PLEASE TRY AGAIN\n");
            printf("Enter the wickets of %s : ",n1.t1name);
            scanf("%d",&n1.w1);
		}                                                                                   //Scanning Wickets
        printf("Enter the wickets of %s : ",n1.t2name);
        scanf("%d",&n1.w2);
        	
        while(n1.w2<0 || n1.w2>10)
        {
            printf("\nInvalid Number of wickets PLEASE TRY AGAIN\n");
            printf("Enter the wickets of %s : ",n1.t2name);
            scanf("%d",&n1.w2);
		}
		
		fp=fopen("cricket.txt","w");                       //Opening the file
		
		fprintf(fp,"...............................................................\n\n");    
        fprintf(fp,"The output of the Created Score Sheet : \n\n");
        fprintf(fp,"Name : %s\n",n1.name);                                         //Printing the Created Score Sheet
        fprintf(fp,"Venue: %s\n\n",n1.venue);
        
    switch(n1.month)
    {
        case 1:
        fprintf(fp,"The Match is Held on %d January %d\n",n1.date,n1.year);
        break;
        
        case 2:
        fprintf(fp,"The Match is Held on %d February %d\n",n1.date,n1.year);
        break;
        
        case 3:
        fprintf(fp,"The Match is Held on %d March %d\n",n1.date,n1.year);
        break;
        
        case 4:
    	fprintf(fp,"The Match is Held on %d April %d\n",n1.date,n1.year);
        break;
        
        case 5:
        fprintf(fp,"The Match is Held on %d May %d\n",n1.date,n1.year);
        break;
        
        case 6:
        fprintf(fp,"The Match is Held on %d June %d\n",n1.date,n1.year);
        break;
        
        case 7:
        fprintf(fp,"The Match is Held on %d July %d\n",n1.date,n1.year);
        break;
        
        case 8:
        fprintf(fp,"The Match is Held on %d August %d\n",n1.date,n1.year);
        break;
        
        case 9:
        fprintf(fp,"The Match is Held on %d September %d\n",n1.date,n1.year);
        break;
        
        case 10:
        fprintf(fp,"The Match is Held on %d October %d\n",n1.date,n1.year);
        break;
        
        case 11:
        fprintf(fp,"The Match is Held on %d November %d\n",n1.date,n1.year);
        break;
        
        case 12:
        fprintf(fp,"The Match is Held on %d December %d\n",n1.date,n1.year);
        break;
    }
        
        fprintf(fp,"\nThe Match Timing : %d:%d:%s\n\n",n1.hour,n1.min,n1.amorpm);
        	
        fprintf(fp,"%s Vs %s\n",n1.t1name,n1.t2name);
        	
        if(n1.tosswinner==1)
        {
            if(n1.t==1)
            {
                fprintf(fp,"%s won the toss and choose to Bat first \n",n1.t1name);
                
            }
            else
            {
            	fprintf(fp,"%s won the toss and choose to Field first \n",n1.t1name);
            }
        }
        else if(n1.tosswinner==2)
        {
            if(n1.t==2)
            {
                fprintf(fp,"%s won the toss and choose to Bat first \n",n1.t2name);
            }
            else
            {
                fprintf(fp,"%s won the toss and choose to Field first \n",n1.t2name);
            }
            
        } 
		fprintf(fp,"\nThe Score of %s is %d - %d ( %.1f )\n",n1.t1name,n1.score1,n1.w1,n1.over1);
        fprintf(fp,"\nThe Score of %s is %d - %d ( %.1f )\n",n1.t2name,n1.score2,n1.w2,n1.over2);
        
        if(n1.score1>n1.score2)
        {
            if(n1.t==1)
            {
                fprintf(fp,"\n%s won the match by %d runs\n",n1.t1name,n1.score1-n1.score2);
            }
            else
            {
                fprintf(fp,"\n%s won the match by %d wickets\n",n1.t1name,10-n1.w1);
            }		
        }		
        else if(n1.score2>n1.score1)
        {
            if(n1.t==2)
            {
            	fprintf(fp,"\n%s won the match by %d runs\n",n1.t2name,n1.score2-n1.score1);
            }
            else
            {
            	fprintf(fp,"\n%s won the match by %d wickets\n",n1.t2name,10-n1.w2);
            }
        }
			
		else 
        fprintf(fp,"\nMatch DRAW - Scores are Equal\n");
        
		fclose(fp);                                               //Closing the file
		
		printf("...............................................................\n\n");    
        printf("The output of the Created Score Sheet : \n\n");
        printf("Name : %s\n",n1.name);                                         //Printing the Created Score Sheet
        printf("Venue: %s\n\n",n1.venue);
		
	switch(n1.month)
    {
        case 1:
        printf("The Match is Held on %d January %d\n",n1.date,n1.year);
        break;
        
        case 2:
        printf("The Match is Held on %d February %d\n",n1.date,n1.year);
        break;
        
        case 3:
        printf("The Match is Held on %d March %d\n",n1.date,n1.year);
        break;
        
        case 4:
        printf("The Match is Held on %d April %d\n",n1.date,n1.year);
        break;
        
        case 5:
        printf("The Match is Held on %d May %d\n",n1.date,n1.year);
        break;
        
        case 6:
        printf("The Match is Held on %d June %d\n",n1.date,n1.year);
        break;
        
        case 7:
        printf("The Match is Held on %d July %d\n",n1.date,n1.year);
        break;
        
        case 8:
        printf("The Match is Held on %d August %d\n",n1.date,n1.year);
        break;
        
        case 9:
        printf("The Match is Held on %d September %d\n",n1.date,n1.year);
        break;
        
        case 10:
        printf("The Match is Held on %d October %d\n",n1.date,n1.year);
        break;
        
        case 11:
        printf("The Match is Held on %d November %d\n",n1.date,n1.year);
        break;
        
        case 12:
        printf("The Match is Held on %d December %d\n",n1.date,n1.year);
        break;
    }
        printf("\nThe Match Timing : %d:%d:%s\n\n",n1.hour,n1.min,n1.amorpm);
        	
        printf("%s Vs %s\n",n1.t1name,n1.t2name);
        	
        if(n1.tosswinner==1)
        {
            if(n1.t==1)
            {
                printf("%s won the toss and choose to Bat first \n",n1.t1name);
                
            }
            else
            {
            	printf("%s won the toss and choose to Field first \n",n1.t1name);
            }
        }
        else if(n1.tosswinner==2)
        {
            if(n1.t==2)
            {
                printf("%s won the toss and choose to Bat first \n",n1.t2name);
            }
            else
            {
                printf("%s won the toss and choose to Field first \n",n1.t2name);
            }
            
        } 
		printf("\nThe Score of %s is %d - %d ( %.1f )\n",n1.t1name,n1.score1,n1.w1,n1.over1);
        printf("\nThe Score of %s is %d - %d ( %.1f )\n",n1.t2name,n1.score2,n1.w2,n1.over2);
        
        if(n1.score1>n1.score2)
        {
            if(n1.t==1)
            {
                printf("\n%s won the match by %d runs\n",n1.t1name,n1.score1-n1.score2);
            }
            else
            {
                printf("\n%s won the match by %d wickets\n",n1.t1name,10-n1.w1);
            }		
        }		
        else if(n1.score2>n1.score1)
        {
            if(n1.t==2)
            {
            	printf("\n%s won the match by %d runs\n",n1.t2name,n1.score2-n1.score1);
            }
            else
            {
            	printf("\n%s won the match by %d wickets\n",n1.t2name,10-n1.w2);
            }
        }
			
		else 
        printf("\nMatch DRAW - Scores are Equal\n");
        
        printf("\nDo you want to Continue the creation ?! if yes Press 2 : ");
        scanf("%d",&n1.flag);
        
    }while(n1.flag== 2 );                  //Repeats the Create Function if 2 is opted ...!!
    
}

int view()                  
{
    int n,k,j,h,m;                       //Viewing The Previous Scores 
    do
    {
    	printf("Choose a League to view Scores of last few matches\n\n");
    	printf("1)IPL 2021\n");
    	printf("2)World T20 2016\n");
    	printf("3)World Cup 2019\n");
    	printf("Enter your choice:");                        //Choice Opted From the User
    	scanf("%d",&k);
    	
	if(k==1)
	{
        printf(".....................................................................\n");
        printf("IPL 2021 is SUSPENDED Due To Covid-19\n\n");
        printf("Choose a most enjoyed Match from below:-\n");
        printf("1)CSK vs. RCB\n");
        printf("2)PBKS vs. RR\n");
        printf("3)CSK vs. KKR\n");
        printf("4)MI vs. CSK\n");
        printf("Enter Your Choice:");
        scanf("%d",&j);     //Enter the team you need to view the Scores  !!
        if(j==1)
        {
           	printf("\nCSK:- 191-4(20)\n");
			printf("RCB:- 122-9(20)\n");
			printf("CSK Won by 69 runs\n");
			printf("Man of the Match :  Ravindra Jadeja\n");
        }
        else if(j==2)
        {
            printf("\nPBKS:- 221-6(20)\n");
            printf("RR:- 217-7(20)\n");
            printf("PBKS Won by 4 runs\n");
            printf("Man of the Match :  Sanju Samson\n");
        }
        else if(j==3)
        {
            printf("\nCSK:- 220-3(20)\n");
            printf("KKR:- 202-10(19.1)\n");
            printf("Csk Won by 18 runs\n");
            printf("Man of the Match :  Faf du Plessis\n");
        }
        else if(j==4)
        {
            printf("\nCSK:- 218-4(20)\n");
            printf("MI:- 219-6(20)\n");
            printf("MI Won by 4 wickets\n");
            printf("Man of the Match :  Kieron Pollard\n");
        }
        else
        printf("Invalid Entry\n");
    }
		
        else if(k==2)
		{
            printf(".....................................................................\n\n");
            printf("World T20 is a Great Fight between Countries\n");
			printf("Choose a Match from last few matches below below:-\n");
            printf("1)Semi Final 1\n");
            printf("2)SemiFinal 2\n");
            printf("3)Final\n");
            printf("Enter your choice:");
            scanf("%d",&h);   
            
            if(h==1)
            {
                printf("\nNew Zealand vs. England\n");
                printf("NZ:- 153-8(20)\n");
                printf("ENG:- 159-3(17.1)\n");
                printf("England Won by 7 wickets\n");
                printf("Man of the Match : Jason Roy\n");
            }
            
            else if(h==2)
            {
                printf("\nIndia vs. West Indies\n");
                printf("IND:- 192-2(20)\n");
                printf("WI:- 196-3(19.4)\n");
                printf("West Indies Won by 7 wickets\n");
                printf("Man of the Match : Lendl Simmons\n");
            } 
            
            else if(h==3)
            {
                printf("\nWest Indies vs. England\n");
                printf("ENG:- 155-9(20)\n");
                printf("WI:- 161-6(19.4)\n");
                printf("West Indies Won by 4 wickets\n");
                printf("Man of the Match : Marlon Samuels\n");
            }
            else
            {
                printf("Invalid Entry\n");
			}
        }	
        
        else if(k==3)
        {
            printf("...............................................................\n\n");
			printf("World Cup 2019 is a heart-breaking league\n");
            printf("Choose a Match from last few matches below below:-\n");
            printf("1)Semi Final 1\n"); 
            printf("2)SemiFinal 2\n");
            printf("3)Finals\n");
            printf("Enter your choice : ");
            scanf("%d",&m); 
            
            if(m==1)
            {
                printf("\nNew Zealand vs. India\n");
                printf("NZ:- 239-8(50)\n");
                printf("IND:- 221-10(49.3)\n");
                printf("New Zealand Won by 18 runs\n");
                printf("Man of the Match :  Matt Henry\n");
            }
            
            else if(m==2)
            {
                printf("\nAustralia vs. England\n");
                printf("AUS:- 229-10(49)\n");
                printf("ENG:- 226-2(32.1)\n");
                printf("England Won by 8 wickets\n");
                printf("Man of the Match :  Chris Woakes\n");
            }
            
            else if(m==3)
            {
                printf("\nNew Zealand vs. England\n");
                printf("NZ:- 241-8(50) & 15-1(super over)\n");
                printf("ENG:- 241-10(49.6) & 15-0(super over)\n");
                printf("England Won the Super Over by Boundaries Count\n");
                printf("Man of the Match :  Ben Stokes\n");
            }
            else
            {
                printf("\nInvalid Entry \n");
            }
		}
		
		else
        {
            printf("Invalid Entry \n");               
        }
        
        printf("\nIf You Want To See The Scores Again ?If Yes Press 3 : ");
        scanf("%d", &n);
        	
    }while(n==3);                //Viewing the Scores Repeats if 3 is opted....!!!
}
