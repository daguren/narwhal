#include "NarwhalApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"

template<>
InputParameters validParams<NarwhalApp>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  return params;
}

NarwhalApp::NarwhalApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  NarwhalApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  NarwhalApp::associateSyntax(_syntax, _action_factory);
}

NarwhalApp::~NarwhalApp()
{
}

// External entry point for dynamic application loading
extern "C" void NarwhalApp__registerApps() { NarwhalApp::registerApps(); }
void
NarwhalApp::registerApps()
{
  registerApp(NarwhalApp);
}

// External entry point for dynamic object registration
extern "C" void NarwhalApp__registerObjects(Factory & factory) { NarwhalApp::registerObjects(factory); }
void
NarwhalApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void NarwhalApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { NarwhalApp::associateSyntax(syntax, action_factory); }
void
NarwhalApp::associateSyntax(Syntax & syntax, ActionFactory & action_factory)
{
}
