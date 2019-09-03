1 Introduction
This set of programming assignments is designed to materialize all of the major operating systems concepts in the CS 446/646 course by allowing you to make design decisions during development of an operating system. These assignments will increase your understanding of operating systems and incorporate common aspects of industry and/or advanced academia.
Over the course of the semester, you will complete one introductory assignment and three simulation assignments. Graduate students will have to complete all the assignments in C. After the completion of all the simulation assignments, you will have simulated the core components of a modern day operating system. Each of the assignments build tremendously upon the previous assignment, thus it is advantageous for you to design each assignment with all future assignments in mind. This will significantly reduce your workload in the long run.
This document may change throughout the semester and suggestions may be made for any changes one week prior to the assignment due date. This is however at the instructor’s discretion.
All of the simulation assignments must be completed using C++ programming language for undergraduate students and C for graduate students. All programs require the use of a make file. ALL PROGRAMS MUST RUN AND COMPILE IN THE ECC, OTHERWISE YOUR GRADE WILL RESULT IN A ZERO. Your submissions must include source code, readme, and makefile.
1
2 Simulator Description 2.1 Expectations
A rubric will be provided for each program. In addition to the rubric, the following will be expected of each program throughout the simulation assignments:
• since you will have an overview of all of the programs, it will be worth your time to consider the subsequent phases as you develop the first programs; if you have an overlying strategy from the beginning, extending each program will not be difficult
• you may work with any number of fellow students to develop your program design, related data structures, algorithmic actions, and so on for each phase. If you do, you must note which students with whom you worked in your upload text on WebCampus; this is for your protection. Failure to do so will result in zero points.
• that said, once you begin coding each phase, you may not discuss, or work, with anyone on your programming, strategy(s), debugging, and so on; it will behoove you to make sure you have a high- quality design developed prior to beginning your coding process
• all programs must be eminently readable, meaning any reasonably competent programmer should be able to sit down, look at your code, and know how it works in a few minutes. This does not mean a large number of comments are necessary; your code itself should read clearly. You are also required to follow a documentation format in your code. If you would like an example on documentation, search ”code documentation” in a search engine. You will be graded on the readability of your code and difficulty in reading your code may result in a reduced grade
• the program must demonstrate all the software development practices expected of a 400- (or 600-) level course. For example, all potential file failures must be resolved elegantly, any screen presentation must be of high quality, any data structures or management must demonstrate high quality, supporting actions and components must demonstrate effective modularity with the use of functions, and so on. This means your code should be tested for failure and handled accordingly, including informing the user of the errors encountered in your simulator
• you may use any I/O libraries or classes as needed, but any other classes must be created by you. In addition, you may use POSIX/pthread operations to manage your I/O operations but you may not use previously created threads such as timer threads (e.g., sleep, usleep, etc.). Additionally, you are free to use basic error libraries but the errors must be handled by you
• for each programming assignment, each student will upload the program files through WebCampus. The file for each student must be tarred or zipped in Linux as specified below, and must be able to be unzipped on any of the ECC computers include any and all files necessary for the operation of the program. Any extraneous files such as unnecessary library or data files will be cause for credit reduction. The format for submission is Sim0X <LastNameFirstName>.tar.gz where X represents the specific project number, or as an example, Sim01 SmithJohn.tar.gz Points will be deducted for incorrect file name format.
• all programs must run on the computers in the ECC with no errors or warnings. 2.2 Meta-Data
All assignments will use meta-data to house the information required to run each simulation. The meta acts as the set of instructions for your simulation to run on. The meta-data codes are as follows:
• S - Operating System, used with start and end
• A - Program Application, used with start and end
     2

• P - Process, used with run
• I - used with Input operation descriptors such as hard drive, keyboard, mouse
• O - used with Output operation descriptors such as hard drive, monitor, printer • M - Memory, used with block, allocate
The meta-data descriptors are as follows:
• begin, finish, hard drive, keyboard, mouse, monitor, run, allocate, printer, block The meta-data will always follow the format:
                   <META DATA CODE>(<META DATA DESCRIPTOR>)<NUMBER OF CYCLES>
Below is an example meta-data file:
1 Start Program Meta-Data Code:
2 S{begin}0; A{begin}0; P{run}11; I{hard drive}9; I{keyboard}12;
3 I{mouse}9; O{hard drive}11; O({monitor}8; O{printer}14; M{block}14; M{allocate}12;
4 A{finish}0; S{finish}0.
5 End Program Meta-Data Code.
2.3 Configuration
Each assignment will use a configuration file to set up the OS simulation for use. This will specify the various cycle times associated with each computer component, memory, and any other necessary informa- tion required to run the simulation correctly. All cycle times are specified in milliseconds. For example, if the hard drive cycle time is 50 ms/cycle and you must run for 5 cycles, the hard drive must run for 250 ms. Log File Path is the name of the new file which will display the output. These will be used by a timer to accurately display timestamps for each OS operation. You must use an onboard clock interface of some kind to manage this, and the precision must be to the microsecond level. The configuration will need to be read in prior to running any processes. The configuration file will be key to setting the constraints under which your simulation will run.
Below is an example configuration file:
1 Start Simulator Configuration File
2 Version/Phase: 2.0
3 File Path: Test_2e.mdf
4 Projector cycle time {msec}: 25
5 Processor cycle time {msec}: 10
6 Keyboard cycle time {msec}: 50
7 Monitor display time {msec}: 20
8 Scanner cycle time {msec}: 10
9 Hard drive cycle time {msec}: 15
10 Log: Log to Both
11 Log File Path: logfile_1.lgf
12 End Simulator Configuration File
2.4 Running the Simulator
When running the simulator you will be required to input a single configuration file (extension .conf). You will run the simulator from the command line similar to the following:
         3

./simX config 1.conf
X represents the assignment number. Many configuration files should be used to test your program, which you may modify for testing purposes as you see fit.
2.5 Turning in Assignments
All assignments will be turned into WebCampus. You must submit a zipped .tar.gz archive as specified above. Inside the archive there should only be the files required to run the simulator (e.g., all source files, all header files). No resource files are allowed. Late assignments will not be accepted.
3 Assignment 1 3.1 Description
Assignment 1 tests your knowledge of strings, reading from files, and data structures. This assignment allows you to create a library of functions/classes for use in later projects. Keep in mind that you will be using many of the functions/classes you create in this phase of the simulator in future phases. Assignment 1 is designed as a data structures problem, and is not a part of the official simulator.
3.2 Specification
You will be given an arbitrary number of configuration files to read into your simulation program. Each configuration file will contain a version number (from 1-4), which will change the content of the configuration file and must be handled accordingly. Along with the configuration files, a number of test meta-data files will be given. Note that the configuration file used for testing will be the same as the example file shown below. You will need to read in the information on each file and display the metrics for them. The grader should be able to easily read and run your code. Include only the makefile and any source or header files in your zipped archive. Refer to the Expectations Section for how to submit your archive to Webcampus.
For the configuration file you will:
• Output all of the cycle times in the format below
• Log to a file/monitor as specified
• Read from the meta-data file specified
• Log to the specified file location (ONLY if logging to the file)
For the meta-data file you will:
• Output each operation and the total time for which it would run (e.g., Ohard drive5 would run for 5 × hard drive cycle time)
Additionally you will be required to:
• handle file failures and typos (this includes a missing file, an incorrect file path, a typo in the file name, etc.)
• handle meta-data and configuration typos (this includes misspellings in the configuration or meta data file, incorrect characters such as a colon instead of a semi-colon, etc.)
• correctly identify and handle missing data (such as a missing processor cycle time or a time of 0)
• utilize a (set of) data structure(s) to organize information and compute information through the data
structure
• open and close any files only once (for reading/writing only)
  4

• document EVERY function and data structure used throughout the program (anyone should look at your code and be able to read it like a book, you can find examples of code documentation by running a search on it)
• The configuration file must be taken as a command line argument during code execution.
• use a makefile
As a reminder, all of the functions created in this assignment will be used for your future assignments and are designed to help you easily transition from understanding data structures to actually applying them in the context of an operating system.
3.3 Example Configuration File
1 Start Simulator Configuration File
2 Version/Phase: 1.0
3 File Path: Test_1a.mdf
4 Monitor display time {msec}: 20
5 Processor cycle time {msec}: 10
6 Mouse cycle time {msec}: 25
7 Hard drive cycle time {msec}: 15
8 Keyboard cycle time {msec}: 50
9 Memory cycle time {msec}: 30
10 Printer cycle time {msec}: 10
11 Log: Log to Both
12 Log File Path: logfile_1.lgf
13 End Simulator Configuration File
3.4 Example Input
1 Start Program Meta-Data Code:
2 S{begin}0; A{begin}0; P{run}11; M{allocate}2;
3 O{monitor}7; I{hard drive}8; I{mouse}8; O{printer}20;
4 P{run}6; O{printer}4; M{block}6;
5 I{keyboard}17; M{block}4; O{printer}8; P{run}5; P{run}5;
6 O{hard drive}6; P{run}18; A{finish}0; S{finish}0.
7 End Program Meta-Data Code.
3.5 Example Output
1 Configuration File Data
2 Monitor = 20 ms/cycle
3 Processor = 10 ms/cycle
4 Mouse = 25 ms/cycle
5 Hard Drive = 15 ms/cycle
6 Keyboard = 50 ms/cycle
7 Memory = 30 ms/cycle
8 Printer = 10 ms/cycle
9 Logged to: monitor and logfile_1.lgf
10
11 Meta-Data Metrics
     5

12 P{run}11 - 110 ms
13 M{allocate}2 - 60 ms
14 O{monitor}7 - 140 ms
15 I{hard drive}8 - 120 ms
16 I{mouse}8 - 200 ms
17 O{printer}20 - 200 ms
18 P{run}6 - 60 ms
19 O{printer}4 - 40 ms
20 M{block}6 - 180 ms
21 I{keyboard}17 - 850 ms
22 M{block}4 - 120 ms
23 O{printer}8 - 80 ms
24 P{run}5 - 50 ms
25 P{run}5 - 50 ms
26 O{hard drive}6 - 90 ms
27 P{run}18 - 180 ms
 6
