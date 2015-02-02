#ifndef DB_CONFIGURATOR_HPP
#define DB_CONFIGURATOR_HPP

#include <string>
#include <boost/property_tree/ptree.hpp>

using namespace std;

class Configurator {

    boost::property_tree::ptree* pt;

    public:
        static Configurator& getInstance();

        ///
        /// \brief Open the file to start reading config
        ///
        /// \param file Path to the file to read from
        ///
        /// \return bool Return true if able to read the file, false else
        bool readConfig(string file);

        boost::property_tree::ptree* getSettings();
    
    private:
        Configurator();
        Configurator(Configurator const&);
        void operator=(Configurator const&);
};

#endif
