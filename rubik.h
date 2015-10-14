#include <iostream>
#include <map>
#include <string>
#include <array>
using namespace std;

// flu refers to the front face (because f is first) of the cubie that
// has a front face, a left face, and an upper face.
// yob refers to the colors yellow, orange, blue that are on the
// respective faces if the cube is in the solved position.
const int rgw = 0, flu = 0; 
const int gwr = 1, luf = 1;
const int wrg = 2, ufl = 2; 

const int rwb = 3, fur = 3; 
const int wbr = 4, urf = 4; 
const int brw = 5, rfu = 5; 

const int ryg = 6, fdl = 6; 
const int ygr = 7, dlf = 7; 
const int gry = 8, lfd = 8; 

const int rby = 9, frd = 9; 
const int byr = 10, rdf = 10;
const int yrb = 11, dfr = 11; 

const int owg = 12, bul = 12; 
const int wgo = 13, ulb = 13; 
const int gow = 14, lbu = 14; 

const int obw = 15, bru = 15;
const int bwo = 16, rub = 16; 
const int wob = 17, ubr = 17; 

const int ogy = 18, bld = 18;
const int gyo = 19, ldb = 19;
const int yog = 20, dbl = 20;

const int oyb = 21, bdr = 21;
const int ybo = 22, drb = 22;
const int boy = 23, rbd = 23;

// Front face rotated clockwise.
array<int, 24> F = {fdl, dlf, lfd, flu, luf, ufl, frd, rdf, dfr, fur, urf, rfu, 
     	            bul, ulb, lbu, bru, rub, ubr, bld, ldb, dbl, bdr, drb, rbd};
// Front face rotated anticlockwise.
array<int, 24> Fi;

// Lower face rotated clockwise.
array<int, 24> L = {ulb, lbu, bul, fur, urf, rfu, ufl, flu, luf, frd, rdf, dfr,
     	            dbl, bld, ldb, bru, rub, ubr, dlf, lfd, fdl, bdr, drb, rbd};
// Lower face rotated anticlockwise.
array<int, 24> Li;

// Upper face rotated clockwise.
array<int, 24> U = {rfu, fur, urf, rub, ubr, bru, fdl, dlf, lfd, frd, rdf, dfr,
                    luf, ufl, flu, lbu, bul, ulb, bld, ldb, dbl, bdr, drb, rbd};
// Upper face rotated anticlockwise.
array<int, 24> Ui;

// Identity: equal to (0, 1, 2, ..., 23).
// Final destination position
array<int, 24> I = {flu, luf, ufl, fur, urf, rfu, fdl, dlf, lfd, frd, rdf, dfr,     bul, ulb, lbu, bru, rub, ubr, bld, ldb, dbl, bdr, drb, rbd};

// Key-Value -> 'F'|'Fi'|'L'|'Li'|'U'|'Ui' : F|Fi|L|Li|U|Ui
map <string, array<int, 24> > quarter_twist;

// Key-Value -> F|Fi|L|Li|U|Ui : 'F'|'Fi'|'L'|'Li'|'U'|'Ui'
map <array<int, 24>, string > quarter_twist_name;

class rubik {
public:
	rubik(){
		// Set all the anticlockwise move
		Fi = perm_inverse(F);
		Li = perm_inverse(L);
		Ui = perm_inverse(U);

		// Map all quater moves
		quarter_twist["F"] = F;
		quarter_twist["Fi"] = Fi;
		quarter_twist["L"] = L;
		quarter_twist["Li"] = Li;
		quarter_twist["U"] = U;
		quarter_twist["Ui"] = Ui;	

		// Inverse mapping of quater move
		quarter_twist_name[F] = "F";
		quarter_twist_name[Fi] = "Fi";
		quarter_twist_name[L] = "L";
		quarter_twist_name[Li] = "Li";
		quarter_twist_name[U] = "U";
		quarter_twist_name[Ui] = "Ui";
	}

	// Inverse permuatation for all anticlockwise moves
	array<int, 24> perm_inverse(array<int, 24>& X){
		array<int, 24> Xi;
		for(int i=0;i<24;i++) Xi[X[i]] = i;
		return Xi; 
	}

	// Apply permutaion on the current position
	array<int, 24> perm_apply(string move, array<int, 24> postion){
		array<int, 24> perm = quarter_twist[move];
		array<int, 24> newPosition;

		for(int i=0;i<24;i++) newPosition[i] = postion[perm[i]];
		return newPosition;
	}

	
};

