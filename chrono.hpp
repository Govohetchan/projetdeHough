#ifndef __CHRONOHPP__
#define __CHRONOHPP__

#include <chrono>

namespace TP_M1
{
	class Chrono
	{
	public:
		void start() 
		{ 
			begin = std::chrono::high_resolution_clock::now(); 
		}
		void stop() 
		{ 
			end = std::chrono::high_resolution_clock::now(); 
		}
		double timeSpan() const
		{ 
			return (std::chrono::duration_cast<std::chrono::duration<double>>(end - begin)).count();  
		}
	
	private:
		std::chrono::high_resolution_clock::time_point begin;
		std::chrono::high_resolution_clock::time_point end;
	};
}

#endif 
