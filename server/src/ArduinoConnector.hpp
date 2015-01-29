#ifndef H_ARDUINOCONNECTOR
#define H_ARDUINOCONNECTOR

#include <string>
#include <vector>


class ArduinoConnector
{

 public:

  // Methodes
  static ArduinoConnector* instance(); // Instanciation unique
  bool connect();
  void waiting(int time);
  void sendCommand(std::string command, std::vector<std::string> data) const;
  std::vector<std::string> getDataFromPin(int pin) const;
    
 
 private:
  
  // attributs
  bool m_isConnected;
  static ArduinoConnector* m_instance;
  
  // Methodes
  ArduinoConnector(); // Constructeur
  void send(std::vector<std::string> data) const;
  std::vector<std::string> get(int pin) const;
    
};

#endif
