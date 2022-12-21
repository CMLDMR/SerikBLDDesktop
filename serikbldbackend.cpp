#include "serikbldbackend.h"

SerikBLDBackend::SerikBLDBackend()
{

}

void SerikBLDBackend::registerQML()
{
    qmlRegisterType<SerikBLDBackend>("com.serik",1,0, "SerikBLDBackend");
}
