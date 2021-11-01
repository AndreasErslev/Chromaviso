﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace StatePattern
{
    public class Solid : On
    {
        private readonly bool modeType = true;
        public override void HandleMode(object sender, On context)
        {
            context.SetModeState(new Strobe());
        }
    }
}