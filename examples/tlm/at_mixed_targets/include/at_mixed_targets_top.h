/*****************************************************************************

  Licensed to Accellera Systems Initiative Inc. (Accellera) under one or
  more contributor license agreements.  See the NOTICE file distributed
  with this work for additional information regarding copyright ownership.
  Accellera licenses this file to you under the Apache License, Version 2.0
  (the "License"); you may not use this file except in compliance with the
  License.  You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
  implied.  See the License for the specific language governing
  permissions and limitations under the License.

 *****************************************************************************/
 
//=====================================================================
///  @file example_system_top.h
 
///  @brief This class instantiates components that compose the TLM2 
///         example system 

//=====================================================================
//  Original Authors:
//    Anna Keist, ESLX
//    Bill Bunton, ESLX
//    Jack Donovan, ESLX
//=====================================================================

#ifndef __EXAMPLE_SYSTEM_TOP_H__
#define __EXAMPLE_SYSTEM_TOP_H__

#include "reporting.h"
#include "at_target_1_phase.h"                      // at memory target
#include "at_target_2_phase.h"                      // at memory target
#include "at_target_4_phase.h"                      // at memory target
#include "initiator_top.h"                          // processor abstraction initiator
#include "models/SimpleBusAT.h"                     // Bus/Router Implementation

/// Top wrapper Module
class example_system_top             
: public sc_core::sc_module                         //  SC base class
{
  public:
	
  /// Constructor
	
  example_system_top              
  ( sc_core::sc_module_name name
  ); 

  void
  limit_thread                                      ///< limit_thread
  ( void
  );

  // Member Variables
  
  private:
  
  SimpleBusAT<2, 3>       m_bus;                    ///< simple bus
  sc_core::sc_time        m_simulation_limit;       ///< simulation time limit
  at_target_1_phase       m_at_target_1_phase_1;    ///< 1 phase target
  at_target_2_phase       m_at_target_2_phase_1;    ///< 2 phase target
  at_target_4_phase       m_at_target_4_phase_1;    ///< 4 phase target
  initiator_top           m_initiator_1;            ///< instance 1 initiator
  initiator_top           m_initiator_2;            ///< instance 2 initiator
};

#endif /* __EXAMPLE_SYSTEM_TOP_H__ */
