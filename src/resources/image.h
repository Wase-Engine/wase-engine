#pragma once

namespace wase::resources
{
	struct Image
	{
		unsigned char* data;
		int width;
		int height;
		int channels;
	};
}