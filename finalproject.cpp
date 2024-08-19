// login and sign up
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include<Windows.h>
#include<bits/stdc++.h>

using namespace std;
struct User {
    string username;
    string password;
    string email;
};
fstream file;
void display();

void intro() {
    cout << endl << endl << endl << endl << "\t\t\t\t\t"; Sleep(900);
    cout << "\n\t\t\t\t\t         ||||      |||||||||| |||||||||| ||||||||||  |||||||||  ||||   |||| ||||||||||  |||| |||||||||"; Sleep(200);
    cout << "\n\t\t\t\t\t        ||  ||     ||||       |||    ||| |||    |||  ||||       ||||   |||| ||||  ||||  |||| |||||||||"; Sleep(200);
    cout << "\n\t\t\t\t\t       |||  |||    |||||||    |||||||||| |||    |||  |||||||||  ||||||||||| ||||  ||||  |||| |||    "; Sleep(200);
    cout << "\n\t\t\t\t\t      ||||||||||   |||||||    |||||||    |||    |||  |||||||||         |||| ||||  ||||  |||| |||      "; Sleep(200);
    cout << "\n\t\t\t\t\t     |||      |||  ||||       ||| ||||   |||    |||       ||||  ||||   |||| ||||  ||||  |||| |||||||||"; Sleep(200);
    cout << "\n\t\t\t\t\t    ||||      |||| |||||||||| |||  ||||| ||||||||||  |||||||||  ||||||||||| ||||  |||||||||| |||||||||"; Sleep(200);
    cout << endl << endl << "\t\t\t"; Sleep(300);
    
    cout << "\n\n\t\t\t\t\t\t\t\t\t\tProject Prepared by:"; Sleep(400);
    cout << "\n\n\t\t\t\t\t\t\t\t\t\t--------------------"; Sleep(500);
    Sleep(1000);
    cout << "\n\n\t\t\t\t\t\t\t\t\t aryan chaudhry      9922103194";
   
    
    Sleep(3500);
    system("cls");
    

}
void login()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t\t\t     ================= LOGIN ================= \n\n";
    file.open("Login_Details.txt", file.in);
    string Username, Email, Pass, ConPass, loginUsername, loginPass, line;
    bool UserFound = false, PassFound = false;

    cout << "\n\n\t\t\t\t\t\t\t\tPlease enter your Username: ";
    getchar();
    getline(cin, loginUsername);

    cout << "\n\n\t\t\t\t\t\t\t\tPlease enter your Password: ";

    // Password input with masking
    for (int i = 0; i > -1; i++)
    {
        char temp;
        temp = _getch();
        if (temp != 13 && temp != 8)
        {
            _putch('*');
        }
        if (temp == 13)
        {
            break;
        }
        if (temp == 8 || temp == 127 && !loginPass.empty())
        {
            cout << "\b \b";
            loginPass.erase(loginPass.size() - 1);
        }
        else
            loginPass += temp;
    }

    cout << "\n\n";

    // Check if user credentials exist in the file
    while (getline(file, line))
    {
        stringstream ss(line);
        getline(ss, Username, '-');
        getline(ss, Pass, '-');
        getline(ss, Email, '-');

        if (Username == loginUsername)
        {
            UserFound = true;
            if (Pass == loginPass)
            {
                PassFound = true;
                break;
            }
        }
    }

    file.close();

    if (UserFound && PassFound)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tLogin successful! \n";
        cout << "\n\n\t\t\t\t\t\t\t\tWelcome, " << loginUsername << "!\n";
        cout << "\n\n\t\t\t\t\t\t\t\tLoading";
        Sleep(200);
        cout << "."; Sleep(200);
        cout << "."; Sleep(400);
        cout << "."; Sleep(200);
        cout << "."; Sleep(200);
        cout << "."; Sleep(200);
        Sleep(1000);
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\t\tInvalid Username or Password! Please try again.\n";
        Sleep(2000);
        system("cls");
        intro();
        display();
    }
}

void Registration()
{
    system("cls");
    cout << "\n\t\t\t\t\t\t\t\t     ================= REGISTRATION ================= \n\n";

    //File to write Login Details:
    file.open("Login_Details.txt", file.app);
    string Username, Email, Pass = "", ConPass = "";
    bool UserNotFound = true, userNameCorrect = false;
    int myCount;

    //Username:
    cout << "\n\n\t\t\t\t\t\t\t\tPlease enter your Username: ";
user:
    getchar();
    getline(cin, Username);
    myCount = 0;

    //to check special characters:
    for (int i = 0; i < Username.length(); i++) {
        if (Username[i] >= 'a' && Username[i] <= 'z' || Username[i] >= 'A' && Username[i] <= 'Z' || Username[i] >= '0' && Username[i] <= '9' || Username[i] == '@' || Username[i] == '.' || Username[i] == '_' || Username[i] == '-') {
            userNameCorrect = true;
            myCount++;
            continue;
        }
        else if (Username[i] == ' ') {
            userNameCorrect = true;
            myCount++;
            continue;
        }
        else {
            userNameCorrect = false;
            break;
        }
    }

    //to check number of characters
    if (userNameCorrect == false) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\t\tSpecial characters are not allowed! You can only use \'-\' and \'_\'\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your UserName:\t";
        goto user;
    }
    else {
        userNameCorrect = false;
    }
    if (myCount <= 2) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\t\tYour Username must be atleast 3 characters long!\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your UserName:\t";
        goto user;
    }
    else {
        userNameCorrect = false;
    }

    //Email:
    cout << "\n\n\t\t\t\t\t\t\t\tPlease enter a valid Email ID: ";
start:
    getline(cin, Email);
    int addretNo, dotNo;
    bool emailCorrect = false;

    //check if space exist
    for (int i = 0; i <= Email.length(); i++) {
        if (Email[i] == ' ') {
            emailCorrect = false;
            break;
        }
        else {
            emailCorrect = true;
            continue;
        }
    }
    if (emailCorrect == false) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\t\tSpace is not allowed in e-mail.\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    else if (emailCorrect == true) {
        emailCorrect == false;
    }



    //Check for special characters
    for (int i = 0; i < Email.length(); i++) {
        if (Email[i] >= 'a' && Email[i] <= 'z' || Email[i] >= 'A' && Email[i] <= 'Z' || Email[i] >= '0' && Email[i] <= '9' || Email[i] == '@' || Email[i] == '.' || Email[i] == '_' || Email[i] == '-') {
            emailCorrect = true;
            continue;
        }
        else {
            emailCorrect = false;
            break;
        }
    }
    if (emailCorrect == false) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\tSpecial characters are not allowed! You can only use \'-\' and \'_\'\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your Email:\t";
        goto start;
    }
    else if (emailCorrect == true) {
        emailCorrect = false;
    }

    //check for @
    for (int i = 0; i <= Email.length(); i++) {
        if (Email[i] == '@') {
            emailCorrect = true;
            addretNo = i;
            break;
        }
        else {
            emailCorrect = false;
            continue;
        }
    }
    if (emailCorrect == false) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\tYour email is invalid! \'@\' is must in an E-mail Address.\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    else if (emailCorrect == true) {
        emailCorrect == false;
    }

    //check number of characters before @
    int myCounVar = 0;
    for (int i = 0; i <= Email.length(); i++) {
        if (Email[i] == '@') {
            break;
        }
        else {
            myCounVar = myCounVar + 1;
        }
    }
    if (myCounVar++ <= 2) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\tYou must have at least three characters in your E-mail before \'@\'.\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    else if (emailCorrect == true) {
        emailCorrect == false;
    }

    //Check if another @ exist?
    for (int i = addretNo + 1; i <= Email.length(); i++) {
        if (Email[i] == '@') {
            emailCorrect = true;
            break;
        }
        else {
            emailCorrect = false;
            continue;
        }
    }
    if (emailCorrect == true) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\tYour email is invalid! You cannot use more than one \'@\'.\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        emailCorrect == false;
        goto start;
    }

    

    //check if . exist?
    dotNo = 0;
    for (int i = 0; i <= Email.length(); i++) {
        if (Email[i] == '.') {
            emailCorrect = true;
            dotNo = i;
            break;
        }
        else {
            emailCorrect = false;
            continue;
        }
    }
    if (emailCorrect == false) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\tYou havent follow the email rules \'.\' is must!\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    else if (emailCorrect == true) {
        emailCorrect == false;
    }

    //check if another . exist?
    for (int i = dotNo + 1; i <= Email.length(); i++) {
        if (Email[i] == '.') {
            emailCorrect = false;
            break;
        }
        else {
            emailCorrect = true;
            continue;
        }
    }
    if (emailCorrect == false) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\t\tYou cannot use more than one \'.\'!\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    else if (emailCorrect == true) {
        emailCorrect == false;
    }

    //check if email have atleast three characters before '.'
    int count = 0;
    for (int i = addretNo + 1; i < dotNo; i++) {
        count = count + 1;
    }
    if (count <= 2) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\t\tyou must have atleast three characters after \'@\'!\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        emailCorrect = false;
        goto start;
    }
    int anotherCount = 0;
    //check if com exist?
    for (int i = dotNo + 1; i <= Email.length(); i++) {
        anotherCount++;
    }
    if (anotherCount <= 2) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\tYour E-mail must have an high level definition of domain having at least \'3\' characters\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    else if (anotherCount >= 6) {
        Beep(1000, 600);
        cout << "\n\n\t\t\t\t\t\tYour E-mail must have an high level definition of domain having at max \'5\' characters\n";
        cout << "\n\n\t\t\t\t\t\t\t\tPlease Re-enter Your E-mail:\t";
        goto start;
    }
    
    check6:
    cout << "\n\n\t\t\t\t\t\t\t\tPlease enter the password that you will use to login: ";
    for (int i = 0; i > -1; i++)
    {
        char temp;
        temp = _getch();
        if (temp != 13 && temp != 8)
        {
            _putch('*');
        }
        if (temp == 13)
        {
            break;
        }
        if (temp == 8 || temp == 127 && !Pass.empty())
        {
            cout << "\b \b";
            Pass.erase(Pass.size() - 1);
        }
        else
            Pass += temp;
    }
    cout << "\n\n\t\t\t\t\t\t\t\tPlease enter your password again for confirmation: ";
    for (int i = 0; i > -1; i++)
    {
        char temp;
        temp = _getch();
        if (temp != 13 && temp != 8)
        {
            _putch('*');
        }
        if (temp == 13)
        {
            break;
        }
        if (temp == 8 || temp == 127 && !ConPass.empty())
        {
            cout << "\b \b";
            ConPass.erase(ConPass.size() - 1);
        }
        else
            ConPass += temp;
    }
    cout << "\n\n";
    if (Pass != ConPass)
    {
        cout << "\n\n\t\t\t\t\t\t\t\tPassword do not match, please try again! ";
        Pass = "";
        ConPass = "";
        goto check6;
    }
    else
    {
        cout << "\n\n\t\t\t\t\t\t\t\tRegistration successful! \n";
        file << Username << "-" << Pass << "-" << Email << "\n";
        file.close();
        cout << "\n\n\t\t\t\t\t\t\t\tLoading"; Sleep(200);
        cout << "."; Sleep(200);
        cout << "."; Sleep(400);
        cout << "."; Sleep(200);
        cout << "."; Sleep(200);
        cout << "."; Sleep(200);
        Sleep(1000);
        login();
    }
}

// code 2 
// graph codes 
 
struct FlightDetail {
    // int sno;
    string name;
    string src;
    string dest;
    string date;
    char flitype;
    int cost;
    vector<string> path;
};   // file handling structure


// graph class for airports

class Graph {
public:
    unordered_map<string, vector<pair<string, int>>> adjList;

    void addAirport( string airport) {
        if (adjList.find(airport) == adjList.end()) {
            adjList[airport] = vector<pair<string, int>>();
        }
    }

    void addEdge(string airport1, string airport2, int distance) {
        adjList[airport1].push_back({airport2, distance});
        adjList[airport2].push_back({airport1, distance}); // Assuming undirected graph
    }
// DFS FUNCTION

void dfs(string& src, string& des, vector<string>& path, vector<vector<string>>& paths, unordered_map<string, bool>& visited) {
       
            path.push_back(src);
        if (src == des) {
            paths.push_back(path);
            path.pop_back();
            return;
        }
    visited[src] = true;
      
       for (auto& it : adjList[src]) {
          if (!visited[it.first]) {
                dfs(it.first, des, path, paths, visited);
            }
           }

                visited[src] = false;
                path.pop_back();
    }

// find paths of given source and destination 

    vector<vector<string>> findAllPaths( string& src, string& des) {
        vector<vector<string>> paths;
        vector<string> path;
        unordered_map<string, bool>visited;

        dfs(src, des, path, paths, visited);

        return paths;
    }



// MINIMUM DISTANCE CODE

   vector<pair<string, int>> findShortestPathDijkstra(string src, string des) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
        unordered_map<string, int> dist;
        unordered_map<string, pair<string, int>> parent;

        for (const auto& it : adjList) {
            dist[it.first] = INT_MAX;
        }

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u_dist = pq.top().first;
            string u = pq.top().second;
            pq.pop();

            if (u_dist > dist[u]) continue;

            if (u == des) break;  // Stop as soon as destination is reached

            for ( auto& neighbor : adjList[u]) {
                string v = neighbor.first;
                int weight = neighbor.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    parent[v] = {u, weight};
                    pq.push({dist[v], v});
                }
            }
        }

        // Construct the shortest path
        vector<pair<string, int>> path;
        string curr = des;
        while (curr != src) {
            path.push_back({curr, parent[curr].second});
            curr = parent[curr].first;
        }
        path.push_back({src, 0});
        reverse(path.begin(), path.end());

        return path;
    }

 int getDistance(string airport1, string airport2) {
        for ( auto& edge : adjList[airport1]) {
            if (edge.first == airport2) {
                return edge.second;  // return distance between airport1 and airport2
            }
        }
        return -1;  // return -1 if no direct route found
    }

};


// writing to file 
void writetofile( FlightDetail & detail) {
   ofstream outFile("Booking_Details.txt");  // Open file in append mode
    if (outFile.is_open()) {
        outFile <<detail.name << "," << detail.src << "," << detail.dest << "," << detail.date << ","<< detail.flitype << "," << detail.cost<<",";
        for (auto& airport : detail.path) {
        outFile << airport << ",";
          }
        outFile << "\n";
        outFile.close();
        cout << "Flight detail added successfully !" <<endl;
        cout<<"********************"<<endl;
        cout<<endl;
    } 
    else {
        cout << "Unable to open file!" << endl;
    }
}

//  reading from file 
void printflightticket( string& targetName) {
    ifstream inFile("Booking_Details.txt");
    FlightDetail detail;

    if (inFile.is_open()) {
        string line;
        while (getline(inFile, line)) {
            istringstream iss(line);
            string name,src,dest, date,flitypeStr;
            char flitype;
            int cost;
            vector<std::string> path;

            getline(iss, name, ',');
            getline(iss, src, ',');
            getline(iss, dest, ',');
            getline(iss, date, ',');
            getline(iss, flitypeStr, ',');
            flitype = flitypeStr[0];
            iss >> cost;
            

            string airport;
            while (getline(iss, airport, ',')) {
                path.push_back(airport);
            }
         
            if (name == targetName) {
                detail.name = name;
                detail.src = src;
                detail.dest = dest;
                detail.date = date;
                detail.flitype = flitype;
                detail.cost = cost;
                detail.path = path; 
                
                cout<<"*************************"<<endl;
                 cout << "Flight found!" << endl;
                 cout<<endl;
                cout << "Name: " << detail.name << endl;
                cout << "Source: " << detail.src << endl;
                cout << "Destination: " << detail.dest <<endl;
                cout << "Date: " << detail.date << endl;
                cout << "Flight Type: " << detail.flitype << endl;
                cout << "Cost: " << detail.cost << endl;
                cout << "Path: ";
                for ( auto& airport : detail.path) {
                    cout << airport << " -> ";
                }
                cout<<"**************************"<<endl;
                cout << endl;
                  
                inFile.close();
                 return;
            }
        }
        inFile.close();
    } 
    else {
        cout << "Unable to open file!" << endl;
    }

   cout<<"Flight not found !"<<endl;
}

void deleteLineFromFile(string& filename,string& targetName) {
    ifstream inFile(filename);
    ofstream outFile("temp.txt");  // Temporary file to write non-matching lines

    if (inFile.is_open() && outFile.is_open()) {
        string line;
        bool found = false;  

        while (getline(inFile, line)) {
            istringstream iss(line);
            string name;
            char delimiter = ',';

            // Read the name from the line
            getline(iss, name, delimiter);

            if (name == targetName) {
                found = true;
                continue;  // Skip writing this line to temp.txt
            }
            outFile << line << endl;
        }

        inFile.close();
        outFile.close();

        // Remove the original file
        remove(filename.c_str());

        // Rename the temporary file to the original filename
        rename("temp.txt", filename.c_str());

        if (found) {
            cout << "Ticket with name "<<targetName<<" deleted successfully!" << endl;
        } else {
            cout << "Target name not found!" << endl;
        }
    } else {
        cout << "Unable to open file!" << endl;
    }
}

  

void minidist(Graph & airportGraph, string & src , string & des){
    vector<pair<string, int>> shortestPath = airportGraph.findShortestPathDijkstra(src, des);
    cout << "Shortest path from " << src << " to " << des << " is:" << endl;
    cout<<endl;
  cout<<"**********************"<<endl;
    for (auto it = shortestPath.begin(); it != shortestPath.end(); ++it) {
        cout << it->first;
        if (it + 1 != shortestPath.end()) {
            cout << " -> ";
        }
    }
    cout << " (Total Distance: " << accumulate(shortestPath.begin(), shortestPath.end(), 0,
                                                [](int sum, const auto& pair) {
                                                    return sum + pair.second;
                                                }) << " km)" << endl;
}

// string matching for fuzzy search

int levenshteinDistance(string& s1, string& s2) {
    int m = s1.length();
    int n = s2.length();
    
    // Create a 2D DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Initialize the DP table
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }
    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    // Compute the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            int cost = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1, dp[i - 1][j - 1] + cost});
        }
    }

    return dp[m][n];
}

vector<string> findSimilarFlights(string& userInput,vector<string>& flightNames) {
    vector<string> similarFlights;
    
    for (auto& flightName : flightNames) {
        if (levenshteinDistance(userInput, flightName) <= 1) {  // Adjust the threshold as needed
            similarFlights.push_back(flightName);
        }
    }
    return similarFlights;
}


void bookflight(Graph &airportGraph ){
   
   string src , des;
   cout<<"ENTER YOUR SOURCE AIRPORT :"<<endl;
   cin>>src;
   cout<<"ENTER YOUR DESTINATION AIRPORT :"<<endl;
   cin>>des;
   
   cout<<endl;


// checks if inputed airports are in adjList or not 

        vector<string> flightNames={"DEL","MUM", "BLR", "JAI", "CDG","LUK","KOL","PAT"};

  if (airportGraph.adjList.find(src) == airportGraph.adjList.end()) {
        cout<<endl;
        cout<<src<<" airport is NOT FOUND !"<<endl;
        cout<<" SEARCHING FOR SIMILAR AIRPORTS NAME"<<endl;
       vector<string> similarFlights = findSimilarFlights(src, flightNames);
       
        if (similarFlights.empty()) {
        cout << "No similar flights found." << endl;
        cout << "Invalid source or destination airport!" << endl;
        cout<<"ENTER AVAILABLE AIRPORTS ONLY"<<endl;
        cout<<endl;
        return;
    }
    else {
        cout << "Similar flights found:" << endl;
        cout<<"select src from these "<<endl;
        for (auto& flight : similarFlights) {
            cout << flight << endl;
        }
    }
      string src2;
      cin>>src2;
       
       src = src2;
      
    }
  if (  airportGraph.adjList.find(des) == airportGraph.adjList.end())
   {   
        cout<<des<<" airport is NOT FOUND "<<endl;
        cout<<"SEARCHING FOR SIMILAR AIRPORTS NAME"<<endl;
        cout<<endl;


       vector<string> similarFlights = findSimilarFlights(des, flightNames);
       

        if (similarFlights.empty()) {
        cout << "No similar flights found." << endl;
        cout << "Invalid source or destination airport!" << endl;
        cout<<"ENTER AVAILABLE AIRPORTS ONLY"<<endl;
        cout<<endl;
        return;
    }
    else {
        cout << "Similar flights found:" << endl;
        cout<<"select des from these "<<endl;
        for (auto& flight : similarFlights) {
            cout << flight << endl;
        }
    
    }
       string des2;
       cin>>des2;
       des = des2;
       
    }


   cout<<"SHOWING FLIGHTS FROM "<<src<<" TO "<<des<<"........... "<<endl;
   cout<<endl;
   
  vector<vector<string>> paths = airportGraph.findAllPaths(src, des);
   
   if(paths.empty()){
    cout<<"NO PATHS FOUND BETWEEN "<<src<<" AND "<<des<<endl;
   }
   // PRINTING ALL PATHS
else{
    cout<<endl;

   cout << "All paths from " << src << " to " << des << " are:" << endl;
   cout<<endl;

   cout<<"*******************"<<endl;
    for( auto& path : paths) {
        for(auto it = path.begin(); it != path.end(); ++it) {
            cout << *it;
            if(it+1!=path.end()) 
            cout<<" -> ";
        }
        cout << endl;
    }

cout<<"*******************"<<endl;
cout<<endl;
    // Find the path with the minimum number of nodes
    int minnodes = INT_MAX;
    vector<string> pathminnodes;

    for (auto &path : paths) {
        int nodes = path.size();
        if (nodes < minnodes) {
            minnodes = nodes;
            pathminnodes = path;
        }
    }

   //FILTERING PATHS ON BASIS OF NUMBER OF STATIONS AND TOTAL DISTANCE
   int ch2;
   cout<<"ENTER 1 TO FIND PATH WITH MINIMUM DISTANCE"<<endl;
   cout<<"ENTER 2 TO FIND PATH WITH LESS AIRPORTS"<<endl;
   cout<<"ENTER 3 TO RETURN TO MAIN"<<endl;
   cout<<" OR ENTER ANYTHING TO CONTINUE WITH BOOKING FLIGHT"<<endl;
   cout<<endl;
   cin>>ch2;

   switch(ch2){
     case 1: 
         minidist(airportGraph,src,des);
         cout<<"******************************"<<endl;
         cout<<endl;
    break;
    
     case 2 : 
     cout << "Path with minimum number of airports from " << src << " to " << des << " is:" << endl;
     for (auto it = pathminnodes.begin(); it != pathminnodes.end(); ++it) {
        cout<<*it;
        if (it + 1 != pathminnodes.end()) {
            cout << " -> ";
        }
    }
    cout<<"  ";
    cout<<"(Total nodes in this path is : "<<minnodes<<" )"<<endl;
    cout<<"*******************************"<<endl;
     cout<<endl;
     break;
     
     case 3: 
       return;
       break;

    default:
     break;
         
   }
   
  cout<<endl;

   char c;
   cout<<"DO YOU WANT TO BOOK FLIGHT TICKET(y/n)"<<endl;
   cin>>c;
   if(c=='y'){
      string nam;
      cout<<"Enter your name "<<endl;
      cin>>nam;
     cout<<"SELECT WHICH OF GIVEN PATHS YOU WANT TO TRAVEL "<<endl;
    int num=1;
    for( auto& path : paths) {
        cout<<num<<") ";
        for(auto it = path.begin(); it != path.end(); ++it) {
            cout << *it;
            if(it+1!=path.end()) 
            cout<<" -> ";
        }
        num++;
        cout << endl;
    }
    int ch3;
    cin>>ch3;
    
   vector<string> vec = paths[ch3-1];
  
  cout<<"ENTER THE DATE YOU WANT TO BOOK YOUR FLIGHT IN dd/mm/yy format : ";
  string date;
  cin>>date;
 
 // cost

   int cost = 0;
        for (int i = 0; i < vec.size() - 1; ++i) {
            int dist = airportGraph.getDistance(vec[i], vec[i + 1]);
            if (dist != -1) {
                cost += dist;
            }
        }
    //    cout<<"cost of your flight is "<<cost<<endl;

       char type;
       cout<<"Enter your flight seat class Economy(E) or Buisness class(B) "<<endl;
       cin>>type;
       
       if(type =='E'){
          cout<<"cost of your flight is "<<cost<<endl;
       }
       else{
        if(type=='B'){
        cost = cost*2;
          cout<<"cost of your flight is "<<cost<<endl;
        }
        else{
            cout<<"wrong entry "<<endl;
        }
       }

    // push name , path , date, cost of flight in flight details of user of login id
   FlightDetail detail;
   
   detail.name = nam;
   detail.src = src;
   detail.dest = des;
   detail.date = date;
  detail.flitype =type;
  detail.cost = cost;
  detail.path = vec;

   writetofile(detail);

    cout<<"CONGRATULATIONS! your TICKET from "<<src<<" to "<<des<<" is booked ! "<<endl;
   }
   else{
    if(c=='n'){
       return;
    }
    else{
     cout<<"SORRY! INVALID COMMAND ! ENTER 'y' OR 'n' "<<endl;
     cout<<endl;
    }
   }
  
}
}

void cancel(){
  // delete booked flight 
  string filename = "Booking_Details.txt";
  string targetname;
  cout<<"Enter the name from which ticket is booked "<<endl;
  cin>>targetname;

  deleteLineFromFile(filename,targetname);

}
void print(){
// print ticket from file 
string targetname;
cout<<"Enter the name on which ticket is booked "<<endl;
cin>>targetname;

 printflightticket(targetname);

}

void fun(Graph & airportGraph){
   int ch;
    do{
    cout<<endl;
   cout<<"ENTER A CHOICE "<<endl;
   cout<<"1) BOOK A TICKET "<<endl;
   cout<<"2) CANCEL A TICKET "<<endl;
   cout<<"3) SEE YOUR BOOKED TICKET "<<endl;
   cout<<"4) EXIT "<<endl;

   cin>>ch;
  
  switch(ch){
    case 1 : 
    bookflight(airportGraph);
    break;

    case 2 :
        cancel();
        break;
    case 3:
        print();
        break;
    case 4 :
       cout << "Exiting..." << endl;
       cout << "THANKS FOR VISITING US..." << endl;
       break;

    default:
       cout << "Invalid choice! Please try again." << endl;
       break;
  }
    } while(ch<4);

}

// MAIN FUNCTION 
int main(){
  intro();
  display();
  
  Graph airportGraph;

    // Adding airports
    airportGraph.addAirport("DEL");
    airportGraph.addAirport("JAI");
    airportGraph.addAirport("CDG");
    airportGraph.addAirport("MUM");
    airportGraph.addAirport("LUK");
    airportGraph.addAirport("KOL");
    airportGraph.addAirport("PAT");
    airportGraph.addAirport("BLR");
    
    // Adding distances between airports
    airportGraph.addEdge("DEL", "JAI", 475);

    airportGraph.addEdge("DEL", "CDG", 740);

    airportGraph.addEdge("DEL", "MUM", 11391);

    airportGraph.addEdge("JAI", "CDG", 1745);

    airportGraph.addEdge("JAI", "MUM", 6235);

    airportGraph.addEdge("LUK", "JAI", 300);

    airportGraph.addEdge("KOL", "JAI", 7345);

    airportGraph.addEdge("CDG", "LUK",2065 );

    airportGraph.addEdge("BLR", "MUM", 804);

    airportGraph.addEdge("DEL", "BLR",8760);

    airportGraph.addEdge("LUK", "PAT", 453);

    airportGraph.addEdge("PAT", "KOL", 682);

    airportGraph.addEdge("BLR", "KOL", 5682);
    

    fun(airportGraph);

   return 0;
}

void display(){
    char choice;

  cout<<"ENTER WHETHER TO LOGIN OR TO REGISTER(l/r)";
  cin>>choice;

  if(choice=='r'){
    Registration();
  }

  else{
    if(choice=='l'){
    login();
    }

    else{
        cout<<"INVALID CHOICE ! ENETER l or r ONlY TO CONTINUE"<<endl;
    }
  }
}