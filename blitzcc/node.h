
#ifndef NODE_H
#define NODE_H

#include "ex.h"
#include "toker.h"
#include "environ.h"
#include "codegen.h"

#define NEWSTRINGS

struct VarNode;
struct ConstNode;

struct Node{
	virtual ~Node(){}

	//tmp_str counter
	static int tmp_strs;

	//used user funcs...
	static std::set<std::string> usedfuncs;

	//Eek! std::list of const std::string labels!
	static std::vector<std::string> const_strings;

	//helper funcs
	static void ex();
	static void ex( const std::string &e );
	static void ex( const std::string &e,int pos );
	static void ex( const std::string &e,int pos,const std::string &f );

//	static void debugStmt( int pos,Codegen *g );

	static std::string genLabel();
	static VarNode *genLocal( Environ *e,Type *ty );

	static TNode *compare( int op,TNode *l,TNode *r,Type *ty );
	static ConstNode *constValue( Type *ty );

	static int enumVars( Environ *e );
	static Type *tagType( const std::string &s,Environ *e );

	static TNode *createVars( Environ *e );
	static TNode *deleteVars( Environ *e );

	static TNode *seq( TNode *l,TNode *r );
	static TNode *move( TNode *src,TNode *dest );
	static TNode *global( const std::string &s );
	static TNode *local( int offset );
	static TNode *arg( int offset );
	static TNode *mem( TNode *ref );
	static TNode *add( TNode *l,TNode *r );
	static TNode *mul( TNode *l,TNode *r );
	static TNode *iconst( int n );
	static TNode *ret();
	static TNode *jsr( const std::string &s );
	static TNode *jump( const std::string &s );
	static TNode *jumpt( TNode *cond,const std::string &s );
	static TNode *jumpf( TNode *cond,const std::string &s );
	static TNode *jumpge( TNode *l,TNode *r,const std::string &s );
	static TNode *call( const std::string &func,TNode *a0=0,TNode *a1=0,TNode *a2=0 );
	static TNode *fcall( const std::string &func,TNode *a0=0,TNode *a1=0,TNode *a2=0 );
	static TNode *strcall( const std::string &func,TNode *a0=0,TNode *a1=0,TNode *a2=0 );
};

#endif
