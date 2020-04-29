/* Processed by ecpg (4.11.0) */
/* These include files are added by the preprocessor */
#include <ecpglib.h>
#include <ecpgerrno.h>
#include <sqlca.h>
/* End of automatic include section */

#line 1 "test.pgc"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sqlda.h>
#include <pgtypes_date.h>    
#include <pgtypes_numeric.h>
    
sqlda_t *sqlda1;
sqlda_t *sqlda2;
/* exec sql begin declare section */
 
 
     
 
   
 
 
 
 

#line 12 "test.pgc"
 char query [ 20000 ] , x [ 20000 ] ;
 
#line 13 "test.pgc"
 char c , * ans ;
 
#line 14 "test.pgc"
 const char * password , * username , * name , * search ;
 
#line 15 "test.pgc"
 int i = 0 , intval , cnt = 0 ;
 
#line 16 "test.pgc"
 long long longlongval ;
 
#line 17 "test.pgc"
 float realval ;
 
#line 18 "test.pgc"
 date dateval ;
 
#line 19 "test.pgc"
 numeric numericval ;
 
#line 20 "test.pgc"
 short shortval ;
/* exec sql end declare section */
#line 21 "test.pgc"

/* exec sql whenever sqlerror  call print_sqlca ( ) ; */
#line 22 "test.pgc"


void print_sqlca()
{
    fprintf(stderr, "==== sqlca ====\n");
    fprintf(stderr, "sqlcode: %ld\n", sqlca.sqlcode);
    fprintf(stderr, "sqlerrm.sqlerrml: %d\n", sqlca.sqlerrm.sqlerrml);
    fprintf(stderr, "sqlerrm.sqlerrmc: %s\n", sqlca.sqlerrm.sqlerrmc);
    fprintf(stderr, "sqlerrd: %ld %ld %ld %ld %ld %ld\n", sqlca.sqlerrd[0],sqlca.sqlerrd[1],sqlca.sqlerrd[2],
                                                          sqlca.sqlerrd[3],sqlca.sqlerrd[4],sqlca.sqlerrd[5]);
    fprintf(stderr, "sqlwarn: %d %d %d %d %d %d %d %d\n", sqlca.sqlwarn[0], sqlca.sqlwarn[1], sqlca.sqlwarn[2],
                                                          sqlca.sqlwarn[3], sqlca.sqlwarn[4], sqlca.sqlwarn[5],
                                                          sqlca.sqlwarn[6], sqlca.sqlwarn[7]);
    fprintf(stderr, "sqlstate: %5s\n", sqlca.sqlstate);
    fprintf(stderr, "===============\n");
}


void executequery(){
	printf("\nQuery : ");
	scanf(" %[^\n]",query);
	int firstTime = 1;
	{ ECPGprepare(__LINE__, NULL, 0, "eq", query);
#line 44 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 44 "test.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_execute, "eq", ECPGt_EOIT, ECPGt_EORT);
#line 45 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 45 "test.pgc"

	if(sqlca.sqlcode==0)
	{
		fprintf(stderr, "sucessful\n");
	}
	{ ECPGtrans(__LINE__, NULL, "commit");
#line 50 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 50 "test.pgc"


}

void executequery1(){
	printf("\nQuery : ");
	scanf(" %[^\n]",query);
	int firstTime = 1;
	printf("\nPrice per\tCity\t\tArea\t\tSales Type\n");
	printf("square feet\n");
	{ ECPGprepare(__LINE__, NULL, 0, "eq", query);
#line 60 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 60 "test.pgc"

	/* declare cur1 cursor for $1 */
#line 61 "test.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur1 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "eq", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 62 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 62 "test.pgc"

	while(sqlca.sqlcode==0){

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur1", ECPGt_EOIT, 
	ECPGt_sqlda, &sqlda1, 0L, 0L, 0L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 65 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 65 "test.pgc"

		sqlda_t *cur_sqlda;

		for (cur_sqlda = sqlda1;cur_sqlda != NULL;cur_sqlda = cur_sqlda->desc_next){

			int i;
	        char name_buf[1024];
	        char var_buf[1024];

	        if(sqlca.sqlcode != 0)
	        	break;

	    	point: for (i = 0; i < cur_sqlda->sqld; i++){

	    		sqlvar_t v = cur_sqlda->sqlvar[i];
	    		char *sqldata = v.sqldata;
	    		short sqllen  = v.sqllen;
	    		strncpy(name_buf, v.sqlname.data, v.sqlname.length);
	            name_buf[v.sqlname.length] = '\0';

	            switch (v.sqltype){

	                case ECPGt_char:
	                    memset(&var_buf, 0, sizeof(var_buf));
	                    memcpy(&var_buf, sqldata, (sizeof(var_buf)<=sqllen ? sizeof(var_buf)-1 : sqllen) );
	                    break;

	                case ECPGt_int: /* integer */
	                    memcpy(&intval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", intval);
	                    break;

	                case ECPGt_long_long: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                case ECPGt_float: /* real */
	                    memcpy(&realval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%.2f", realval);
	                    break;

	                case ECPGt_short: /* sort */
	                    memcpy(&shortval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", shortval);
	                    break;

	         

	                case 7: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                default:
	                	{
	                    	int i;
	                    	memset(var_buf, 0, sizeof(var_buf));
	                    	for (i = 0; i < sqllen; i++){
	                     	   char tmpbuf[16];
	                    	    snprintf(tmpbuf, sizeof(tmpbuf), "%02x ", (unsigned char) sqldata[i]);
	                    	    strncat(var_buf, tmpbuf, sizeof(var_buf));
	                   		}
	                	}
	                    break;

	                }
			printf("%s \t",var_buf);
	                
	        }
	            printf("\n");
	    }
	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur1", ECPGt_EOIT, ECPGt_EORT);
#line 138 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 138 "test.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 139 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 139 "test.pgc"

}
void executequery2(){
	printf("\nQuery : ");
	scanf(" %[^\n]",query);
	int firstTime = 1;
	printf("\nSellerId\tNo.ofBuyer\tCustomers \tPercentage\n");
	{ ECPGprepare(__LINE__, NULL, 0, "eq", query);
#line 146 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 146 "test.pgc"

	/* declare cur2 cursor for $1 */
#line 147 "test.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur2 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "eq", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 148 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 148 "test.pgc"

	while(sqlca.sqlcode==0){

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur2", ECPGt_EOIT, 
	ECPGt_sqlda, &sqlda1, 0L, 0L, 0L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 151 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 151 "test.pgc"

		sqlda_t *cur_sqlda;

		for (cur_sqlda = sqlda1;cur_sqlda != NULL;cur_sqlda = cur_sqlda->desc_next){

			int i;
	        char name_buf[1024];
	        char var_buf[1024];

	        if(sqlca.sqlcode != 0)
	        	break;

	    	point: for (i = 0; i < cur_sqlda->sqld; i++){

	    		sqlvar_t v = cur_sqlda->sqlvar[i];
	    		char *sqldata = v.sqldata;
	    		short sqllen  = v.sqllen;
	    		strncpy(name_buf, v.sqlname.data, v.sqlname.length);
	            name_buf[v.sqlname.length] = '\0';

	            switch (v.sqltype){

	                case ECPGt_char:
	                    memset(&var_buf, 0, sizeof(var_buf));
	                    memcpy(&var_buf, sqldata, (sizeof(var_buf)<=sqllen ? sizeof(var_buf)-1 : sqllen) );
	                    break;

	                case ECPGt_int: /* integer */
	                    memcpy(&intval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", intval);
	                    break;

	                case ECPGt_long_long: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                case ECPGt_float: /* real */
	                    memcpy(&realval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%.2f", realval);
	                    break;

	                case ECPGt_short: /* sort */
	                    memcpy(&shortval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", shortval);
	                    break;

	         

	                case 7: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                default:
	                	{
	                    	int i;
	                    	memset(var_buf, 0, sizeof(var_buf));
	                    	for (i = 0; i < sqllen; i++){
	                     	   char tmpbuf[16];
	                    	    snprintf(tmpbuf, sizeof(tmpbuf), "%02x ", (unsigned char) sqldata[i]);
	                    	    strncat(var_buf, tmpbuf, sizeof(var_buf));
	                   		}
	                	}
	                    break;

	                }
			printf("%s \t\t",var_buf);
	                
	        }


	            printf("\n");

	    }

	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur2", ECPGt_EOIT, ECPGt_EORT);
#line 229 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 229 "test.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 230 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 230 "test.pgc"


}


void executequery3(){
	printf("\nQuery : ");
	scanf(" %[^\n]",query);
	int firstTime = 1;
	printf("\nSellerId\tMin Age \tMax Age\n");
	{ ECPGprepare(__LINE__, NULL, 0, "eq", query);
#line 240 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 240 "test.pgc"

	/* declare cur3 cursor for $1 */
#line 241 "test.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur3 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "eq", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 242 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 242 "test.pgc"

	while(sqlca.sqlcode==0){

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur3", ECPGt_EOIT, 
	ECPGt_sqlda, &sqlda1, 0L, 0L, 0L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 245 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 245 "test.pgc"

		sqlda_t *cur_sqlda;

		for (cur_sqlda = sqlda1;cur_sqlda != NULL;cur_sqlda = cur_sqlda->desc_next){

			int i;
	        char name_buf[1024];
	        char var_buf[1024];

	        if(sqlca.sqlcode != 0)
	        	break;

	    	point: for (i = 0; i < cur_sqlda->sqld; i++){

	    		sqlvar_t v = cur_sqlda->sqlvar[i];
	    		char *sqldata = v.sqldata;
	    		short sqllen  = v.sqllen;
	    		strncpy(name_buf, v.sqlname.data, v.sqlname.length);
	            name_buf[v.sqlname.length] = '\0';

	            switch (v.sqltype){

	                case ECPGt_char:
	                    memset(&var_buf, 0, sizeof(var_buf));
	                    memcpy(&var_buf, sqldata, (sizeof(var_buf)<=sqllen ? sizeof(var_buf)-1 : sqllen) );
	                    break;

	                case ECPGt_int: /* integer */
	                    memcpy(&intval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", intval);
	                    break;

	                case ECPGt_long_long: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                case ECPGt_float: /* real */
	                    memcpy(&realval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%.2f", realval);
	                    break;

	                case ECPGt_short: /* sort */
	                    memcpy(&shortval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", shortval);
	                    break;

	         

	                case 7: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                default:
	                	{
	                    	int i;
	                    	memset(var_buf, 0, sizeof(var_buf));
	                    	for (i = 0; i < sqllen; i++){
	                     	   char tmpbuf[16];
	                    	    snprintf(tmpbuf, sizeof(tmpbuf), "%02x ", (unsigned char) sqldata[i]);
	                    	    strncat(var_buf, tmpbuf, sizeof(var_buf));
	                   		}
	                	}
	                    break;

	                }
			printf("%s\t \t",var_buf);
	                
	        }
	            printf("\n");

	    }

	}
	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur3", ECPGt_EOIT, ECPGt_EORT);
#line 320 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 320 "test.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 321 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 321 "test.pgc"

}

void executequery4(){
	printf("\nQuery : ");
	scanf(" %[^\n]",query);
	int firstTime = 1;

	printf("\nDifference\tDifference\n");
	printf("from min value\tfrom max value\n");
	{ ECPGprepare(__LINE__, NULL, 0, "eq", query);
#line 331 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 331 "test.pgc"

	/* declare cur4 cursor for $1 */
#line 332 "test.pgc"

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "declare cur4 cursor for $1", 
	ECPGt_char_variable,(ECPGprepared_statement(NULL, "eq", __LINE__)),(long)1,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 333 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 333 "test.pgc"

	while(sqlca.sqlcode==0){

		{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "fetch next from cur4", ECPGt_EOIT, 
	ECPGt_sqlda, &sqlda1, 0L, 0L, 0L, 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EORT);
#line 336 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 336 "test.pgc"

		sqlda_t *cur_sqlda;

		for (cur_sqlda = sqlda1;cur_sqlda != NULL;cur_sqlda = cur_sqlda->desc_next){

			int i;
	        char name_buf[1024];
	        char var_buf[1024];

	        if(sqlca.sqlcode != 0)
	        	break;

	    	point: for (i = 0; i < cur_sqlda->sqld; i++){

	    		sqlvar_t v = cur_sqlda->sqlvar[i];
	    		char *sqldata = v.sqldata;
	    		short sqllen  = v.sqllen;
	    		strncpy(name_buf, v.sqlname.data, v.sqlname.length);
	            name_buf[v.sqlname.length] = '\0';

	            switch (v.sqltype){

	                case ECPGt_char:
	                    memset(&var_buf, 0, sizeof(var_buf));
	                    memcpy(&var_buf, sqldata, (sizeof(var_buf)<=sqllen ? sizeof(var_buf)-1 : sqllen) );
	                    break;

	                case ECPGt_int: /* integer */
	                    memcpy(&intval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", intval);
	                    break;

	                case ECPGt_long_long: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                case ECPGt_float: /* real */
	                    memcpy(&realval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%.2f", realval);
	                    break;

	                case ECPGt_short: /* sort */
	                    memcpy(&shortval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%d", shortval);
	                    break;

	         

	                case 7: /* bigint */
	                    memcpy(&longlongval, sqldata, sqllen);
	                    snprintf(var_buf, sizeof(var_buf), "%lld", longlongval);
	                    break;

	                default:
	                	{
	                    	int i;
	                    	memset(var_buf, 0, sizeof(var_buf));
	                    	for (i = 0; i < sqllen; i++){
	                     	   char tmpbuf[16];
	                    	    snprintf(tmpbuf, sizeof(tmpbuf), "%02x ", (unsigned char) sqldata[i]);
	                    	    strncat(var_buf, tmpbuf, sizeof(var_buf));
	                   		}
	                	}
	                    break;

	                }
			printf("%s\t",var_buf);
	                
	        }


	            printf("\n");

	    }

	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "close cur4", ECPGt_EOIT, ECPGt_EORT);
#line 414 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 414 "test.pgc"

	{ ECPGtrans(__LINE__, NULL, "commit");
#line 415 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 415 "test.pgc"


}

int main()
{
	username = "201601218";
	name = "201601218@10.100.71.21";
	password = "yash";
	search = "realestate1";

	{ ECPGconnect(__LINE__, 0, name , username , password , NULL, 0); 
#line 426 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 426 "test.pgc"

	if(sqlca.sqlcode==0)
    	fprintf(stderr, "Connection Successful\n");
	else
	{
    	fprintf(stderr,"Connection couldn't be established\n");
    	exit(1);
	}

	{ ECPGdo(__LINE__, 0, 1, NULL, 0, ECPGst_normal, "set search_path to $0", 
	ECPGt_char,&(search),(long)0,(long)1,(1)*sizeof(char), 
	ECPGt_NO_INDICATOR, NULL , 0L, 0L, 0L, ECPGt_EOIT, ECPGt_EORT);
#line 435 "test.pgc"

if (sqlca.sqlcode < 0) print_sqlca ( );}
#line 435 "test.pgc"

	if(sqlca.sqlcode==0)
    	fprintf(stderr,"Search_path Successfully set\n");
	else
	{
    	fprintf(stderr,"No such path available\n");
    	exit(1);
	}

	while(1)
	{
    	printf("1. Price per sq ft. in your area\n2. Find the number of buyers whose budget is greater than the average value of seller's properties \n3. Find your target age group  \n4. Find the price range in your city according to your budget\n5. Query\n6. Exit\n");    	
	scanf("%d",&cnt);

    		if(cnt==1){
			executequery1();
		}
		else if(cnt==2){
			executequery2();
		}
	    	else if(cnt==3){
			executequery3();	
		}
		else if(cnt==4){
			executequery4();	
		}	
		else if(cnt==5)
		{
			executequery();
		}
		else{
	    		break;
		}
	}
}
