#ifndef Size_h_
#define Size_h_

#define SIZE2D32 le::help::Size2D32
#define SIZE3D32 le::help::Size3D32
#define SIZE2D16 le::help::Size2D16
#define SIZE3D16 le::help::Size3D16

namespace le {
	namespace help {
		/*
		Size2D16 Struct:
		short width - default=0
		short height - default=0
		*/
		struct Size2D16{
			short width;
			short height;
			Size2D16( ) :width( 0 ), height( 0 ) { }
		};
		/*
		Size3D16 Struct:
		short x - default=0
		short y - default=0
		short z - default=0
		*/
		struct Size3D16{
			short x;
			short y;
			short z;
			Size3D16( ) :x( 0 ), y( 0 ), z( 0 ) { }
		};
		/*
		Size2D32 Struct:
		int width - default=0
		int height - default=0
		*/
		struct Size2D32{
			int width;
			int height;
			Size2D32( ) :width( 0 ), height( 0 ) { }
		};
		/*
		Size3D32 Struct:
		int x - default=0
		int y - default=0
		int z - default=0
		*/
		struct Size3D32{
			int x;
			int y;
			int z;
			Size3D32( ) :x( 0 ), y( 0 ), z( 0 ) { }
		};

	}//NS DEFINITIONS
}//NS LUEN

#endif // Size_h__