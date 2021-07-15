#pragma once
int map[8][8];

void re_map();

void step_up()
{
	re_map();
}

void re_map()
{
	for (int y = 0; y < 8; y++)
	{
		for (int x = 0; x < 8; x++)
		{
			map[y][x] = 0;
		}
	}
}

void print_map()
{
	for (int y = 0; y < 8; y++)
	{
		std::cout << " ---- ---- ---- ---- ---- ---- ---- ---- " << std::endl;
		std::cout << "| ";
		for (int x = 0; x < 8; x++)
		{

			if ( map[y][x] == 0 )  
			{
				int i = x + y;
				
				if (i % 2 == 0)
				{
					std::cout << "□";
				}
				else
				{
					std::cout << "■";
				}
			}
			std::cout << " | ";
		}
		
		std::cout << std::endl;
	}
	std::cout << " ---- ---- ---- ---- ---- ---- ---- ---- " << std::endl;
}

void test()
{

}
