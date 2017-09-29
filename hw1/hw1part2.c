#include <stdio.h>

#define PI 3.14  /*pi sayisini 3.14 olarak constant tanimladim.*/

float diameter(float circumference);  /*  foksiyonun prototipini tanimladim*/
float ageOfTree(float diameter , float growth_factor);  /*  foksiyonun prototipini tanimladim*/


float diameter(float circumference)  /*foksiyonumu tanimladim*/
{
float R; /*cap degeri icin bellekte yer ayirdim.*/
R= circumference/PI;  /*cap degerini bulmak icin circumference degerini pi sayisina boldum.*/
return (R); /*cap degerini dondurdum*/
}


float ageOfTree(float diameter , float growth_factor) /*fonksiyonumu tanimladim*/
{
float age_of_tree; /*agacin yas degeri icin bellekte yer ayirdim*/
age_of_tree=diameter*growth_factor; /*agacin yas degerini bulmak icin cap ile growth factoru carptim ve age_of_tree degiskenine atadim.*/
return(age_of_tree); /*age of tree degiskenine atanan degeri dondurdum*/
}
