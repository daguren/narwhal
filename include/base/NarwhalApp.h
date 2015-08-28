#ifndef NARWHALAPP_H
#define NARWHALAPP_H

#include "MooseApp.h"

class NarwhalApp;

template<>
InputParameters validParams<NarwhalApp>();

class NarwhalApp : public MooseApp
{
public:
  NarwhalApp(InputParameters parameters);
  virtual ~NarwhalApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* NARWHALAPP_H */
