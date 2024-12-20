/*********************
 *                   *
 * 文件夹: ▲01 绪论    *
 *                   *
 * 文件名:: Scanf.cxx *
 *                   *
 *********************/



#ifndef SCANF_CXX
#define SCANF_CXX

#include <cstdio>
#include <cstring>
#include <cstdarg>
#include <cctype>

int Scanf(FILE *fp, char *format, ...)
{
	int *i;
	char *ch, *s;
	float *f;
	int count, k, len, n;		
	int tmp;
	va_list ap;
	
	len = strlen(format);
	
	va_start(ap, format);
	
	for(count=0,k=2; k<=len; k=k+2)
	{
		while((tmp=getc(fp))!=EOF)			//Ìø¹ýËùÓÐ·ÇÎ÷ÎÄ×Ö·û 
		{
			if((tmp>=0 && tmp<=127))
			{
				ungetc(tmp, fp);			//Óöµ½Ê×¸öÎ÷ÎÄ×Ö·û£¬½«´ËÎ÷ÎÄ×Ö·û·ÅÈëÊäÈëÁ÷ 
				break;
			}
		}
		
		if(tmp==EOF)
			break;
		
		if(format[k-1]=='c')				//¶ÁÈ¡×Ö·û		 
		{
			ch = va_arg(ap, char*);
						
			if(tmp!=EOF)
				count += fscanf(fp, "%c", ch);					
		}	
		
		if(format[k-1]=='d')				//¶ÁÈ¡ÕûÐÍ 
		{
			i = va_arg(ap, int*);
			
			while((tmp=getc(fp))!=EOF)
			{
				if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+')
				{
					ungetc(tmp, fp);
					break;
				}
			}
			
			if(tmp!=EOF)
				count += fscanf(fp, "%d", i);
		}

		if(format[k-1]=='f')				//¶ÁÈ¡¸¡µãÐÍ 
		{
			f = va_arg(ap, float*);
			
			while((tmp=getc(fp))!=EOF)
			{
				if((tmp>='0' && tmp<='9') || tmp=='-' || tmp=='+'|| tmp=='.' )
				{
					ungetc(tmp, fp);
					break;
				}
			}
			
			if(tmp!=EOF)
				count += fscanf(fp, "%f", f);
		}
		
		if(format[k-1]=='s')				//¶ÁÈ¡×Ö·û´® 
		{
			s = va_arg(ap, char*);
			
			while((tmp=getc(fp))!=EOF && (!isprint(tmp) || tmp==' '))
				;
			
			n = 0;
			if(!feof(fp))
			{
				ungetc(tmp, fp);
				while((tmp=getc(fp))!=EOF)
				{
					if(isprint(tmp) && tmp!=' ')
						s[n++] = tmp;
					else
						break;	
				}
				ungetc(tmp, fp);			
			}
                                                                                
			s[n] = '\0';
					
			count++;		
		}		
	}
		
	va_end(ap);
	
	return count;
}

#endif 
