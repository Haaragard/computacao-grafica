#pragma once

#include <windows.h>

class Timer
{
private:
	LARGE_INTEGER start, end;	// valores de início e fim do contador
	LARGE_INTEGER freq;			// frequência do contador
	bool stoped;				// estado da contagem

public:
	Timer();					// construtor

	void Start();				// inicia/retoma contagem do tempo
	void Stop();				// para contagem do tempo
	float Reset();				// reinicia contagem e retorna tempo transcorrido
	float Elapsed();			// retorna tempo transcorrido em segundos
	bool Elapsed(float secs);	// verifica se transcorreu "secs" segundos
};

inline bool Timer::Elapsed(float secs)
{
	return (Elapsed() >= secs ? true : false);
}
