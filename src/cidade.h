#ifndef CIDADE_H
#define CIDADE_H

#include <string>

class Cidade
{
public:
  /** Default constructor */
  Cidade(std::string nome, std::string estado):nome(nome), estado(estado){}

  /** Default destructor */
  virtual ~Cidade();

  /** Access nome
   * \return The current value of nome
   */
  std::string getNome() const { return nome; }

  /** Set nome
   * \param val New value to set
   */
  void setNome (std::string val) { nome = val; }

  /** Access estado
   * \return The current value of estado
   */
  std::string getEstado() const { return estado; }

  /** Set estado
   * \param val New value to set
   */
  void setEstado(std::string val) { estado = val; }

private:
  std::string nome; //!< Member variable "nome"
  std::string estado; //!< Member variable "estado"
};

#endif // CIDADE_H
