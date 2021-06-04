Repo For Security in Computing
1. Git clone
2. Install extensions "c/c++" and "vscode-pdf" for VSCode (bottom button on left panel)
3. Open "Security In Computin" folder with VSCode
4. Type "cd {folder name ex: Week 1 or on mac: Week\ 1} then cd {next folder name ex: cd Friday}"

FOR WINDOWS
1. Install mingw, mark C++ compilers for installation
2. Add {mingw location}/bin to PATH System Variables

FOR MAC
1. Install XCode
2. Make sure it is updated, it should come with g++ tools

HOW TO RUN THE CODE
1. Use `gcc *.c -o main -lm`
2. On windows just type in terminal "main.exe" on mac type "./main.exe"

FOR DEBUGGING CODE
1. Use `gcc *.c -o main -lm -fsanitize=address -fno-omit-frame-pointer -g`
2. Run the program, and this will give hints to lines causing possible seg faults.

TO EASILY ACCESS YOUR VM:
1. Open Cisco Anyconnect and connect to https://secure.vpn.ucf.edu and login
2. Enter your NID into the login.bat file in project directory and save
3. In the project directory run "login.bat" and you will be prompted to enter your password

TO EASILY MOVE FILES FROM YOUR PC TO EUSTIS
1. To move all .sh files in a directory, cd into the directory, then use: `scp *.sh <NID>@eustis.eecs.ucf.edu:~/<Folder Name/Directory>/` EX: `scp *.sh <NID>@eustis.eecs.ucf.edu:~/PA1/`
2. To move all files in a directory on your pc, cd into the directory, then use: `scp *.* <NID>@eustis.eecs.ucf.edu:~/<Folder Name/Directory>/`