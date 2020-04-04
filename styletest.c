
/*
 * Training file for TurboVNC Style Checker
 *
 * Copyright (C)2018, 2020 D. R. Commander.  All Rights Reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 *   this list of conditions and the following disclaimer.
 * - Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 * - Neither the name of The VirtualGL Project nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS",
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT HOLDERS OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */


/********** DETECTING WHITESPACE ERRORS **********/

/*--------- Tab characters ---------*/
	something;  /* hit */
  something;  /* miss */

/*--------- Alt-Space ---------*/
  /* hit */
  /* miss */

/*--------- Blank line(s) at top of file ---------*/
  /* See above */

/*--------- General whitespace errors ---------*/
  /* Should hit on "new blank line at EOF" */


/********** DETECTING C++-STYLE COMMENTS **********/
// hit
/* miss */


/********** DETECTING BAD LINE CONTINUATION SPACING **********/
#define something()  /* hit */ \
#define something()  /* hit */\
#define something()  /* miss */  \


/********** DETECTING UNATTACHED else/catch/struct **********/
if (something) {
  something;
}
else (something_else)  /* hit */

if (something) {
  something;
}

else (something_else)  /* hit */

if (something) something;
else (something_else)  /* miss */

if (something) { something; }
else (something_else)  /* miss */

if (something) {
  something;
} else (something_else)  /* miss */

try {
  something;
}
catch (something_else)  /* hit */

try {
  something;
}

catch (something_else)  /* hit */

try {
  something;
} catch (something_else)  /* miss */

typedef struct _mystruct
{  /* hit */
  something;
} mystruct;

typedef struct _mystruct {  /* miss */
  something;
} mystruct;


/********** DETECTING INCORRECT BRACKET SPACING **********/

/*--------- Function-like macro with unattached bracket ---------*/
#define something2()  \
{  \
  something2;  ### hit ###

#define something2()  \
{ something2;  ### hit ###  \

#define something2() {  \
  something2;  ### miss ###

/*--------- Other issues ---------*/

{something;  ### hit ###
{ something;  ### hit ###
something;}  ### hit ###
{something;}  ### hit ###
something; }  /* hit */
; }  /* hit */
{ something; }  /* miss */

something{  ### hit ###
something {  ### miss ###

}something  /* hit */
} something  /* miss */

class Foo {  /* hit */

class Foo  /* miss */
{


/********** DETECTING INCORRECT STATEMENT SPACING **********/
if()  /* hit */
if ()  /* miss */
for()  /* hit */
for ()  /* miss */
else()  /* hit */
else ()  /* miss */
catch()  /* hit */
catch ()  /* miss */
while()  /* hit */
while ()  /* miss */
do()  /* hit */
do ()  /* miss */
switch()  /* hit */
switch ()  /* miss */
do_stuff; do_other_stuff;  ### hit ###
do_stuff;  do_other_stuff;  ### miss ###
do_stuff ;  /* hit */
do_stuff;  /* miss */


/********** DETECTING INCORRECT FUNCTION/TYPE CAST SPACING **********/
  (type*)hello  ### hit ###
  (type *)hello  ### miss ###
  (type**)hello  ### hit ###
  (type **)hello  ### miss ###
  (type) var  ### hit ###
  (type)var  ### miss ###
  (type) "text"  ### hit ###
  (type)"text"  ### miss ###
  (type) &var  ### hit ###
  (type)&var  ### miss ###
  *(type) var  ### hit ###
  *(type)var  ### miss ###
(type) var  ### hit ###
if ((type) var == something)  ### hit ###
(type)var  ### miss ###
(type *) var  ### hit ###
(type **) var  ### hit ###
something + (type) var  ### hit ###
something + (type)var  ### miss ###
  return (type) var  ### hit ###
  return (type)var  ### miss ###
  ((type) var  ### hit ###
  ((type)var  ### miss ###
((type) var  ### hit ###
((type)var  ### miss ###
return ((type) var  ### hit ###
return ((type)var  ### miss ###
(type) (var)  ### hit ###
(type)(var)  ### miss ###
  (*something->method)(args)  /* hit */
  (*something->method) (args)  /* miss */
  ( (*something->method)(args)  /* hit */
  ( (*something->method) (args)  /* miss */
  ((*something->method)(args)  /* hit */
  ((*something->method) (args)  /* miss */
  (*something)(args)  /* hit */
  (*something) (args)  /* miss */


/********** DETECTING INCORRECT MACRO SPACING **********/
#define macro  \
     something;  /* hit */

#define macro
     something;  /* miss */  \

#define macro  \
    something;  /* miss */

#define macro(a, b)  something  /* hit */
#define macro(a, b) something  /* miss */
#define macro()  something  /* hit */
#define macro() something  /* miss */
#define macro(a, b) { \  /* miss */
#define macro(a, b) \  /* miss */

#define  macro  something  /* hit */
#define macro something  /* hit */
#define macro  something  /* miss */


/********** DETECTING INCORRECT COMMA SPACING **********/
comma,comma,down,doobie,doo,down,down,comma,comma  ### hit ###
comma ,comma ,down ,doobie ,doo ,down ,down ,comma ,comma  ### hit ###
comma, comma, down, doobie, doo, down, down, comma, comma  ### miss ###


/********** DETECTING INCORRECT OPERATOR SPACING **********/

/*--------- Incorrect pointer operator spacing ---------*/
char* something;  ### hit ###
char *something;  ### miss ###

/*--------- Incorrect address operator spacing ---------*/
char& something;  ### hit ###
char &something;  ### miss ###

/*--------- No space before other operators ---------*/
### hit ###  something=
### miss ###  something =
### hit ###  (something)=
### miss ###  (something) =
### hit ###  something[something]=
### miss ###  something[something] =

### hit ###  something+=
### miss ###  something +=

### hit ###  something-=
### miss ###  something -=

### hit ###  something*=
### miss ###  something *=

### hit ###  something/=
### miss ###  something /=

### hit ###  something%=
### miss ###  something %=

### hit ###  something&=
### miss ###  something &=

### hit ###  something|=
### miss ###  something |=

### hit ###  something^=
### miss ###  something ^=

### hit ###  something<<=
### miss ###  something <<=

### hit ###  something>>=
### miss ###  something >>=

### hit ###  something+
### miss ###  something++
### miss ###  something +

### hit ###  something-
### miss ###  something--
### miss ###  something -

### hit ###  something*
### miss ###  something *

### hit ###  something/
### miss ###  something /

### hit ###  something%
### miss ###  something %

### hit ###  something==
### miss ###  something ==

### hit ###  something!=
### miss ###  something !=

### hit ###  something>
### miss ###  something >

### hit ###  something<
### miss ###  something <

### hit ###  something>=
### miss ###  something >=

### hit ###  something<=
### miss ###  something <=

### hit ###  something&&
### miss ###  something &&

### hit ###  something||
### miss ###  something ||

### hit ###  something&
### miss ###  something &

### hit ###  something|
### miss ###  something |

### hit ###  something^
### miss ###  something ^

### hit ###  something<<
### miss ###  something <<

### hit ###  something>>
### miss ###  something >>

something? something: something  ### hit ###
something ? something : something  ### miss ###

/*--------- No space after other operators ---------*/
=something  ### hit ###
= something  ### miss [hit on operator continuance] ###
=(something)  ### hit ###
= (something)  ### miss [hit on operator continuance] ###

+=something  ### hit ###
+= something  ### miss [hit on operator continuance] ###

-=something  ### hit ###
-= something  ### miss [hit on operator continuance] ###

*=something  ### hit ###
*= something  ### miss [hit on operator continuance] ###

&=something  ### hit ###
&= something  ### miss [hit on operator continuance] ###

%=something  ### hit ###
%= something  ### miss [hit on operator continuance] ###

/=something  ### hit ###
/= something  ### miss [hit on operator continuance] ###

|=something  ### hit ###
|= something  ### miss [hit on operator continuance] ###

^=something  ### hit ###
^= something  ### miss [hit on operator continuance] ###

<<=something  ### hit ###
<<= something  ### miss [hit on operator continuance] ###

>>=something  ### hit ###
>>= something  ### miss [hit on operator continuance] ###

+something  ### hit ###
++something  ### miss ###
+ something  ### miss [hit on operator continuance] ###

-something  ### miss [can't check because indistinguishable from unary -][hit on operator continuance] ###
--something  ### miss ###
- something  ### miss [hit on operator continuance] ###

*something  ### miss [can't check because indistinguishable from pointer][hit on operator continuance] ###
* something  ### miss [hit on operator continuance] ###

/something  ### hit ###
/ something  ### miss [hit on operator continuance] ###

%something  ### hit ###
% something  ### miss [hit on operator continuance] ###

==something  ### hit ###
== something  ### miss [hit on operator continuance] ###

!=something  ### hit ###
!= something  ### miss [hit on operator continuance] ###

>something  ### hit ###
> something  ### miss [hit on operator continuance] ###

<something  ### hit ###
< something  ### miss [hit on operator continuance] ###

>=something  ### hit ###
>= something  ### miss [hit on operator continuance] ###

<=something  ### hit ###
<= something  ### miss [hit on operator continuance] ###

&&something  ### hit ###
&& something  ### miss [hit on operator continuance] ###

||something  ### hit ###
|| something  ### miss [hit on operator continuance] ###

|something  ### hit ###
| something  ### miss [hit on operator continuance] ###

^something  ### hit ###
^ something  ### miss [hit on operator continuance] ###

<<something  ### hit ###
<< something  ### miss [hit on operator continuance] ###

>>something  ### hit ###
>> something  ### miss [hit on operator continuance] ###

&something  ### miss [can't check because indistinguishable from address][hit on operator continuance] ###
& something  ### miss [hit on operator continuance] ###

something ?something :something  ### hit ###
something ? something : something  ### miss ###

/*--------- [!|~] something ---------*/
! something  ### hit ###
!something  ### miss ###

~ something  ### hit ###
~something  ### miss ###


/********** DETECTING INCORRECT OPERATOR CONTINUANCE **********/
? something  ### hit ###
### miss ###  something ?
: something  ### hit ###
### miss ###  something :


/********** DETECTING INCORRECT FUNCTION SPACING **********/
  something (args)  ### hit ###
  something(args)  ### miss ###
static My_awesome_type
something(args)  ### hit ###
static My_awesome_type something(args)  ### miss ###

