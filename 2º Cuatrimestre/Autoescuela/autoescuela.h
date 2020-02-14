//Inés Prieto Centeno

#ifndef autoescuela_h
#define autoescuela_h

#include <iostream>
#include <unordered_map>
#include <map>

using nombreAlumno = std::string;
using nombreProfesor = std::string;
using puntosAlumno = int;

class autoescuela{
private:
	std::unordered_map<nombreAlumno, nombreProfesor> tabla;
	std::unordered_map<nombreProfesor, std::map<nombreAlumno,puntosAlumno>> tabla2;
public:
	void alta(nombreAlumno alumno, nombreProfesor profesor) {
		if (tabla.count(alumno)) {
			nombreProfesor antiguo = tabla[alumno];
			int puntos = tabla2[antiguo][alumno];
			tabla2[antiguo].erase(alumno);
			tabla.erase(alumno);
			tabla[alumno] = profesor;
			tabla2[profesor][alumno] = puntos;
		}
		else {
			tabla[alumno] = profesor;
			tabla2[profesor][alumno] = 0;
		}
	}

	bool es_alumno(nombreAlumno alumno, nombreProfesor profesor) {
		if (tabla.count(alumno)) {
			if (tabla[alumno] == profesor) return true;
		}
		return false;
	}

	int puntuacion(nombreAlumno alumno) {
		if (tabla[alumno] == "") throw std::domain_error("El alumno " + alumno + " no esta matriculado");
		return tabla2[tabla[alumno]][alumno];
	}

	void actualizar(nombreAlumno alumno, int N) {
		if(!tabla.count(alumno)) throw std::domain_error("El alumno " + alumno + " no esta matriculado");
		tabla2[tabla[alumno]][alumno] += N;
	}

	std::list<nombreAlumno> examen(nombreProfesor profesor, int N) {
		std::list<nombreAlumno> ex;
		for (auto const& t : tabla2[profesor]) {
			if (t.second >= N) ex.push_back(t.first);
		}
		return ex;
	}

	void aprobar(nombreAlumno alumno) {
		if (!tabla.count(alumno)) throw std::domain_error("El alumno " + alumno + " no esta matriculado");
		nombreProfesor antiguo = tabla[alumno];
		tabla.erase(alumno);
		tabla2[antiguo].erase(alumno);
	}

};
#endif // !autoescuela_h
