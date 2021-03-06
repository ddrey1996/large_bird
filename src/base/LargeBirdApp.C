#include "LargeBirdApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<LargeBirdApp>()
{
  InputParameters params = validParams<MooseApp>();
  return params;
}

LargeBirdApp::LargeBirdApp(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  LargeBirdApp::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  LargeBirdApp::associateSyntax(_syntax, _action_factory);
}

LargeBirdApp::~LargeBirdApp()
{
}

// External entry point for dynamic application loading
extern "C" void LargeBirdApp__registerApps() { LargeBirdApp::registerApps(); }
void
LargeBirdApp::registerApps()
{
  registerApp(LargeBirdApp);
}

// External entry point for dynamic object registration
extern "C" void LargeBirdApp__registerObjects(Factory & factory) { LargeBirdApp::registerObjects(factory); }
void
LargeBirdApp::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void LargeBirdApp__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { LargeBirdApp::associateSyntax(syntax, action_factory); }
void
LargeBirdApp::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
