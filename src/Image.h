#pragma once
class Image{	
	public:		
		int width;
		int height;		
		void initData(const char* filename);
		unsigned char* getData() const { return _imgData; }
		void freeData();
	protected:
		unsigned char* _imgData;
};