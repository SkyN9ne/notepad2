#include "EditLexer.h"
#include "EditStyleX.h"

static KEYWORDLIST Keywords_Lua = {{
//++Autogenerated -- start of section automatically generated
"and break do else elseif end false for function goto if in local nil not or repeat return then true until while "

, // 1 basic function
"_G _VERSION assert( bit32 collectgarbage( coroutine debug dofile( error( gcinfo( getmetatable( io ipairs( "
"load( loadfile( loadlib( loadstring( math module( next( os package pairs( pcall( print( "
"rawequal( rawget( rawlen( rawset( require( select( setfenv( setmetatable( string table tonumber( tostring( type( "
"unpack( utf8 warn( xpcall( "

, // 2 metamethod
"__add __band __bnot __bor __bxor __call __close __concat __div __eq __gc __idiv __index __le __len __lt "
"__metatable __mod __mode __mul __name __newindex __pairs __pow __shl __shr __sub __tostring __unm "

, // 3 standard library
"LUA_CPATH LUA_INIT LUA_PATH "
"bit32.arshift( bit32.band( bit32.bnot( bit32.bor( bit32.btest( bit32.bxor( bit32.extract( bit32.lrotate( bit32.lshift( "
"bit32.replace( bit32.rrotate( bit32.rshift( boolean byte( "
"char( close( collect coroutine.close( coroutine.create( coroutine.isyieldable( coroutine.resume( coroutine.running( "
"coroutine.status( coroutine.wrap( coroutine.yield( count "
"debug.debug( debug.getfenv( debug.gethook( debug.getinfo( debug.getlocal( debug.getmetatable( debug.getregistry( "
"debug.getupvalue( debug.getuservalue( debug.setcstacklimit( debug.setfenv( debug.sethook( debug.setlocal( "
"debug.setmetatable( debug.setupvalue( debug.setuservalue( debug.traceback( debug.upvalueid( debug.upvaluejoin( dump( "
"file find( float flush( format( generational gfind( gmatch( gsub( "
"incremental integer io.close( io.flush( io.input( io.lines( io.open( io.output( io.popen( io.read( "
"io.stderr io.stdin io.stdout io.tmpfile( io.type( io.write( isrunning "
"len( lines( lower( "
"match( math.abs( math.acos( math.asin( math.atan( math.atan2( math.ceil( math.cos( math.cosh( math.deg( math.exp( "
"math.floor( math.fmod( math.frexp( math.huge math.ldexp( math.log( math.log10( "
"math.max( math.maxinteger math.min( math.mininteger math.mod( math.modf( math.pi math.pow( "
"math.rad( math.random( math.randomseed( math.sin( math.sinh( math.sqrt( math.tan( math.tanh( math.tointeger( math.type( "
"math.ult( "
"number "
"os.clock( os.date( os.difftime( os.execute( os.exit( os.getenv( os.remove( os.rename( os.setlocale( "
"os.time( os.tmpname( "
"pack( package.config package.cpath package.loaded package.loaders package.loadlib( package.path package.preload "
"package.searchers package.searchpath( package.seeall( packsize( "
"read( rep( restart reverse( "
"seek( setvbuf( step stop string.byte( string.char( string.dump( string.find( string.format( "
"string.gfind( string.gmatch( string.gsub( string.len( string.lower( string.match( string.pack( string.packsize( "
"string.rep( string.reverse( string.sub( string.unpack( string.upper( sub( "
"table.concat( table.foreach( table.foreachi( table.getn( table.insert( table.maxn( table.move( table.pack( "
"table.remove( table.setn( table.sort( table.unpack( thread "
"upper( userdata utf8.char( utf8.charpattern utf8.codepoint( utf8.codes( utf8.len( utf8.offset( write( "

, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL
//--Autogenerated -- end of section automatically generated
}};

static EDITSTYLE Styles_Lua[] = {
	EDITSTYLE_DEFAULT,
	{ SCE_LUA_WORD, NP2StyleX_Keyword, L"fore:#0000FF" },
	{ SCE_LUA_WORD2, NP2StyleX_BasicFunction, L"fore:#FF8000" },
	{ SCE_LUA_WORD3, NP2StyleX_Metamethod, L"fore:#0080FF" },
	{ SCE_LUA_FUNCTION, NP2StyleX_Function, L"fore:#A46000" },
	{ MULTI_STYLE(SCE_LUA_COMMENT, SCE_LUA_COMMENTLINE, SCE_LUA_COMMENTDOC, 0), NP2StyleX_Comment, L"fore:#608060" },
	{ MULTI_STYLE(SCE_LUA_STRING_DQ, SCE_LUA_STRINGEOL, SCE_LUA_LITERALSTRING, SCE_LUA_STRING_SQ), NP2StyleX_String, L"fore:#008000" },
	{ SCE_LUA_NUMBER, NP2StyleX_Number, L"fore:#FF0000" },
	{ SCE_LUA_OPERATOR, NP2StyleX_Operator, L"fore:#B000B0" },
	{ SCE_LUA_PREPROCESSOR, NP2StyleX_Preprocessor, L"fore:#FF8000" },
};

EDITLEXER lexLua = {
	SCLEX_LUA, NP2LEX_LUA,
//Settings++Autogenerated -- start of section automatically generated
	{
		LexerAttr_PrintfFormatSpecifier,
		TAB_WIDTH_4, INDENT_WIDTH_4,
		(1 << 0) | (1 << 1), // class, function
		0,
		'\\', 0, 0,
		SCE_LUA_WORD,
		0, 0,
		SCE_LUA_OPERATOR, 0
		, KeywordAttr32(0, KeywordAttr_PreSorted) // keywords
		| KeywordAttr32(1, KeywordAttr_PreSorted) // basic function
		| KeywordAttr32(2, KeywordAttr_PreSorted) // metamethod
		| KeywordAttr32(3, KeywordAttr_NoLexer) // standard library
	},
//Settings--Autogenerated -- end of section automatically generated
	EDITLEXER_HOLE(L"Lua Script", Styles_Lua),
	L"lua; wlua; nse; luadoc; luax",
	&Keywords_Lua,
	Styles_Lua
};
