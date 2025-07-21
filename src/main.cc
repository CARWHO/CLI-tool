#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function prototypes
void print_line(string line, int index);
void print_file(string filename);
void edit_line(vector<string>& lines, int line_num, string filename);
void save_file(string filename);
int quit_program();
void command(string filename);

void print_line(string line, int index) {
    cout << index << ": " << line << endl;
}

void print_file(string filename) {
        int i = 1;
        ifstream file(filename);
            string line;
        while (getline(file, line)) {
            print_line(line, i);
            i++;
        };
}

void edit_line(vector<string>& lines, int line_num, string filename) {
    string new_text;

    cout << "Edit line " << line_num << ": " << lines[line_num-1] << endl;
    cout << "New text: ";

    getline(cin, new_text);
    lines[line_num-1] = new_text;

    cout << "Successfully updated Line: " << line_num << ". Use 'S' to save all edited lines." <<endl;
}   

void save_file(const vector<string>& lines, const string& filename) {
    ofstream out(filename, ios::trunc);

    for (size_t i = 0; i < lines.size(); ++i) {
        out << lines[i] << '\n';
    }
    cout << "File saved" << endl;
}

int quit_program() {
    cout << "Thanks for using Cli-Tool" << endl;
    exit(EXIT_SUCCESS);
}

void command(string filename) {

    vector<string> file_contents;
    ifstream infile(filename);
    string line;
    int line_num;

    while (getline(infile, line)) {
        file_contents.push_back(line);
    }

    while (true) {

            getline(cin,line);
            istringstream iss(line);
            char cmd; iss >> cmd;

            if (cmd == 'E' ) {
                if (!(iss >> line_num)) {
                cout << "Please specify a line number." << endl;
            } else {
                edit_line(file_contents, line_num, filename);
                }
            }
                
            if (cmd == 'P') {
                print_file(filename);
            }

            if (cmd == 'S') {
                save_file(file_contents, filename);
            }

            if (cmd == 'Q') {
                quit_program();
            }
    }
}

int main(int argc, char* argv[]) {

    auto file = argv[1];
    cout << "Opened: " << file << endl;
    cout << "Welcome to Cli-Tool, P(Print), S(Save), E(Edit)+[Line Number], Q(Quit)" << endl;
    command(file);
    return 0;
}

