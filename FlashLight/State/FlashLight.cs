﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using static StatePattern.FlashLightState;

namespace StatePattern
{

    public class FlashLight : EventArgs, IFlashLight
    {
        // Opsætning af events
        public event EventHandler<IFlashLight> PowerEventOn;
        public event EventHandler<IFlashLight> PowerEventOff;
        public event EventHandler<On> SolidModeEvent;
        public event EventHandler<On> StrobeModeEvent;

        // Opretter abstract state, der kan symbolisere de states tilknyttet FlashLightState
        private FlashLightState _state;
        private On _mode;
        private string _modeActive = "0";

        // Event "Invoke" metode, der aktivere eventhandler (som findes i On, Off og FlashLightState)
        public void Power(IFlashLight e, bool eventActive)
        {
            EventHandler<IFlashLight> handlerOn = PowerEventOn;
            EventHandler<IFlashLight> handlerOff = PowerEventOff;

            // Laver "Invoke" på On evenhandleren
            if (eventActive)
            {
                handlerOn?.Invoke(this, e);
                eventActive = false;
            }
            // Laver "Invoke" på Off evenhandleren
            else if (!eventActive)
            {
                handlerOff?.Invoke(this, e);
                eventActive = true;
            }
        }

        // Bestemmer init state til at være Off
        public FlashLight()
        {
            _state = new Off();

            _mode = new Solid();
            SolidModeEvent += _mode.HandleMode;

            _mode = new Strobe();
            StrobeModeEvent += _mode.HandleMode;

        }
        // Funktion der sætter state, hvis der skiftes til nyt
        public void SetState(FlashLightState s)
        {
            if (_state != s)
            {
                _state = s;

                // Printer hvilket state der er aktivt
                Console.WriteLine("State has changed to: {0}", _state.ActiveState());

                // Bestemmer om der skal tændes eller slukkes, alt efter hvilket state der er aktivt
                if (_state.OnOff()) {
                    
                    Console.WriteLine("Enter FlashLight mode ");
                    Console.Write("Press 1 for Strobe | Press 0 for Solid: ");
                    _modeActive = Console.ReadLine();

                    switch (_modeActive)
                    {
                        case "1":
                            _state.Mode(_state, StrobeModeEvent);
                            break;
                        default:
                            _state.Mode(_state, SolidModeEvent);
                            break;
                    }
                }
            }
        }

        // Symoblisere fysisk FlashLight og bestemmer om FlashLight er tændt eller slukket
        public void LightSwitch()
        {
            if (_state.OnOff())
            {
                if (_state.ModeType())
                {
                    Strobe();
                }

                else if (!_state.ModeType())
                {
                    LightOn();
                }
            }

            else if (!_state.OnOff())
            {
                LightOff();
            }

        }
        private static void LightOn()
        {
            Console.WriteLine("Flashlight is On!");
        }
        private static void LightOff()
        {
            Console.WriteLine("Flashlight is Off!");
        }
        private static void Strobe()
        {
            for (int i = 0; i < 10; i++)
            {
                Console.WriteLine("FLASH!");
                Thread.Sleep(250);
            }
        }
    }
}
