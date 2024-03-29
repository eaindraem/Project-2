Determine an appropriate fine for the overstatement for each property, depending on the overstated amount and location.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

Fall 2023 CS 31
Programming Assignment 2
One Fine Day
Time due: 11:00 PM Thursday, October 19

Before you ask a question about this specification, see if it has already been addressed in the spec or in the Project 2 FAQ. And read the FAQ before you turn in this project, to be sure you didn't misinterpret anything.

(Be sure you also do the homework accompanying this project.)

A very, very well-known businessman has been judged to have fraudulently inflated the values of various properties he owns in order to secure better terms on loans. The judge needs to determine an appropriate fine for the overstatement for each property. The court has assigned a government intern (you) the job of writing a program to calculate the fine for a particular overstated valuation.

Your program must accept as input the identification of a property, the overstated amount in millions of dollars, and the location of the property. The output will tell how much the fine is for that property.

Here is an example of a dialog with the program (user input is shown here in boldface):

	Identification: National Doral Miami
	Overstated amount (in millions): 137
	Location: florida
	---
	The fine for National Doral Miami is $20.526 million.
According to the schedule of fines for these kinds of fraud cases:

For the first 60 million dollars overstated, the fine will be 11.11% of the overstated amount.
In addition, for the next 90 million dollars overstated (beyond the initial 60 million dollars), the fine will be increased by an additional 15.3% of that additional overstated amount. However, if the location is florida or new york (so spelled, entirely in lower case), the amount of this additional amount is 18% of that additional value instead of 15.3%.
In addition, the fine will be further increased in the amount of 21% of the portion of the overstated value that exceeds 150 million dollars.
As an example, The fine for National Doral Miami above would be $6.666M for the first $60M in overstated value, plus $13.86M for the next $77M in overstated value (18% of 77M instead of 15.3%, since the location is florida), for a total of $20.526M.

Here's another example:

	Identification: MacLeod House & Lodge
	Overstated amount (in millions): 155.4
	Location: Scotland
	---
	The fine for MacLeod House & Lodge is $21.570 million.
The fine is 11.11% of $60M, plus 15.3% of $90M, plus 21% of $5.4M.

You can test your understanding of the fine schedule by experimenting with this financial fraud calculator we found at the court's web site.

Your program must collect the information for one property in the manner indicated by the examples, and then write to cout a line with three hyphens only (no spaces or other characters), followed by exactly one line in a format required below. Our grading tool will judge the correctness of your program by examining only the line following the line with three hyphens (and verifying that there are no additional lines). That one line you write must be in one of the following four forms; the text must be identical to what is shown, except that italicized items are replaced as appropriate:

If an empty string was provided for the identification:
   You must enter a property identification.
If the overstated amount is not positive:
   The overstated amount must be positive.
If an empty string was provided for the location:
   You must enter a location.
If the input is valid and none of the preceding situations holds:
   The fine for identification is $amount million.
In the last case, identification must be the identification the user entered, and amount must be the correct fine, shown as a number with at least one digit to the left and exactly three digits to the right of the decimal point, rounded to the nearest .001. It is acceptable if a number like exactly 1.3575, equally near 1.357 and 1.358, rounds to either one of those. The lines you write must not start with any spaces. If you are not a good speller or typist, or if English is not your first language, be especially careful about duplicating the messages exactly. Here are some foolish mistakes that may cause you to get very few points for correctness on this project, no matter how much time you put into it, because the mistake will cause your program to fail most or all of the test cases we run:

Not writing to cout a line with exactly three hyphens in all cases.
Writing any spaces on the line that is supposed to have three hyphens.
Writing more than one line after the line with three hyphens. Don't, for example, add a gratuitous "Honesty is the best policy".
Writing lines to cerr instead of cout.
Writing lines like these:
	The fine for Park Residences Yorktown is $7.340 millon.        misspelling
	The Fine for Park Residences Yorktown is $7.340 million.       wrong capitalization
	The fine for Park Residences Yorktown will be $7.340 million.  wrong text
	The fine for Park Residences Yorktown is $7.340.               missing text
	 The fine for Park Residences Yorktown is $7.340 million.      extra space at start of line
	The fine for Park Residences Yorktown is $ 7.340 million.      extra space
	The fine for Park Residences Yorktown is 7.340 million.        missing dollar sign
	The fine for Park Residences Yorktown is $7.340 million        missing period
	The fine for Park Residences Yorktown is $7.34 million.        missing digit
	The fine for Park Residences Yorktown is $7.3402 million.      extra digit
	The fine for Park Residences Yorktown is $7 million.           missing decimal point and digits
Your program must gather the identification, the overstated amount, and the location in that order. However, if you detect an error in an item, you do not have to request or get the remaining items if you don't want to; just be sure you write to cout the line of three hyphens, the required message, and nothing more after that. If instead you choose to gather all input first before checking for errors, and you detect more than one error, then after writing the line of three hyphens, write only the error message for the earliest erroneous item.

You will not write any loops in this program. This means that each time you run the program, it handles only one property. It also means that in the case of bad input, you must not keep prompting the user until you get something acceptable; our grading tool will not recognize that you're doing that.

A string with no characters in it is the empty string. A string with at least one character in it is not the empty string, even if the only characters in it are things like spaces or tabs. Although realistically it would be silly to have an identiciation consisting of seventeen spaces and nothing more, treat that as you would any other non-empty string: as a valid identification. (Since you don't yet know how to check for that kind of situation anyway, we're not requiring you to.)

The one kind of input error that your program does not have to deal with (because you don't yet know enough to know how to do this nicely), is not finding a number in the input where the overstated amount is expected. We promise that our grading tool will not, for example, supply the text zillions and zillions when your program requests the overstated amount. Notice that the overstated amount need not be an integer.

The correctness of your program must not depend on undefined program behavior. Your program could not, for example, assume anything about n's value at the point indicated:

	int main()
	{
	    int n;
	    int m = 42 * n;  // n's value is undefined
	    …
Your program must build successfully under both g31 and either Visual C++ or clang++.

What you will turn in for this assignment is a zip file containing these three files and nothing more:

A text file named fine.cpp that contains the source code for your C++ program. Your source code should have helpful comments that tell the purpose of the major program segments and explain any tricky code.
A file named report.docx (in Microsoft Word format) or report.txt (an ordinary text file) that contains:
A brief description of notable obstacles you overcame. (In Project 1, for example, some people had the problem of figuring out how to work with more than one version of a program in Visual C++.)
A list of the test data that could be used to thoroughly test your program, along with the reason for each test. You don't have to include the results of the tests, but you must note which test cases your program does not handle in the way this spec requires. (This could happen if you didn't have time to write a complete solution, or if you ran out of time while still debugging a supposedly complete solution.) For Project 1, for example, such a list, had it been required, might have started off like this:
More surveyed than the total for basmati and jasmine (1000, 413, 382 )
Fewer surveyed than the total for basmati and jasmine (500, 413, 382 )
Zero total surveyed (0, 100, 100)
Data giving a non-integer percentage (1000, 413, 382)
More preferring basmati over jasmine (1000, 413, 382)
Equal numbers preferring basmati and jasmine (1000, 500, 500)
…
A file named hw.docx (in Microsoft Word format) or hw.txt (an ordinary text file) that contains your solution to the homework accompanying Project 2.
By October 18, there will be links on the class webpage that will enable you to turn in your zip file electronically. Turn in the file by the due time above. Give yourself enough time to be sure you can turn something in, because we will not accept excuses like "My computer died the afternoon of the day the assignment was due." There's a lot to be said for turning in a preliminary version of your program, report, and homework early (You can always overwrite it with a later submission). That way you have something submitted in case there's a problem later. Notice that most of the test data portion of your report can be written from the requirements in this specification, before you even start designing your program.

The writeup Some Things about Strings tells you what you need to know about strings for this project.

As you develop your program, periodically try it out under another compiler (g31 on cs31.seas.ucla.edu if you're doing your primary development using Visual C++ or Xcode). Sometimes one compiler will warn you about something that another is silent about, so you may be able to find and fix more errors sooner. If running your program under both environments with the same input gives you different results, your program is probably relying on undefined behavior (such as using the value of an uninitialized variable), which we prohibit.
