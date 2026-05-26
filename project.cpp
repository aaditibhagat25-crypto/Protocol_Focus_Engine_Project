//Protocol Focus Engine 

      <!DOCTYPE html>
<html lang="en">
<head>
   <meta charset="UTF-8">
   <meta name="viewport" content="width=device-width, initial-scale=1.0">
   <title>PROTOCOL // Focus Engine</title>
   <script src="https://cdn.tailwindcss.com"></script>
   <link href="https://fonts.googleapis.com/css2?family=Share+Tech+Mono&display=swap" rel="stylesheet">
   <style>
       :root {
           --neon-green: #00ff41;
           --neon-dark: #003b00;
           --neon-blue: #00e5ff;
           --bg-dark: #030a05;
       }


       body {
           font-family: 'Share Tech Mono', monospace;
           background-color: var(--bg-dark);
           color: var(--neon-green);
           overflow-x: hidden;
           margin: 0;
           position: relative;
       }


       .video-background {
           position: fixed;
           top: 0; left: 0; width: 100vw; height: 100vh;
           object-fit: cover;
           z-index: -20;
           opacity: 0.15;
           /* Turns standard video into hacking green */
           filter: sepia(100%) hue-rotate(75deg) saturate(300%) contrast(1.2);
       }


       .scanlines {
           position: fixed;
           top: 0; left: 0; width: 100vw; height: 100vh;
           background: linear-gradient(to bottom, rgba(255,255,255,0), rgba(255,255,255,0) 50%, rgba(0,0,0,0.2) 50%, rgba(0,0,0,0.2));
           background-size: 100% 4px;
           z-index: 100;
           pointer-events: none;
           opacity: 0.6;
       }


       .vignette {
           position: fixed;
           top: 0; left: 0; width: 100vw; height: 100vh;
           background: radial-gradient(circle at center, transparent 30%, var(--bg-dark) 100%);
           z-index: -10;
           pointer-events: none;
       }


       .hologram-ring {
           position: fixed;
           border: 1px dashed rgba(0, 255, 65, 0.2);
           border-radius: 50%;
           transform-style: preserve-3d;
           z-index: -15;
           pointer-events: none;
       }
      
       .ring-1 {
           width: 80vw; height: 80vw;
           top: 10vh; left: 10vw;
           animation: rotate3d 30s linear infinite;
       }
      
       .ring-2 {
           width: 50vw; height: 50vw;
           bottom: -10vh; right: -10vw;
           border: 2px solid rgba(0, 229, 255, 0.1);
           animation: rotate3d-reverse 40s linear infinite;
       }


       @keyframes rotate3d {
           0% { transform: rotateX(60deg) rotateY(20deg) rotateZ(0deg); }
           100% { transform: rotateX(60deg) rotateY(20deg) rotateZ(360deg); }
       }
       @keyframes rotate3d-reverse {
           0% { transform: rotateX(70deg) rotateY(-20deg) rotateZ(360deg); }
           100% { transform: rotateX(70deg) rotateY(-20deg) rotateZ(0deg); }
       }


       .glitch {
           position: relative;
           display: inline-block;
       }
       .glitch::before, .glitch::after {
           content: attr(data-text);
           position: absolute;
           top: 0; left: 0;
           width: 100%; height: 100%;
           background: var(--bg-dark);
       }
       .glitch::before {
           left: 2px;
           text-shadow: -2px 0 #ff003c;
           animation: glitch-anim-1 2s infinite linear alternate-reverse;
       }
       .glitch::after {
           left: -2px;
           text-shadow: 2px 0 #00e5ff;
           animation: glitch-anim-2 3s infinite linear alternate-reverse;
       }


       @keyframes glitch-anim-1 {
           0% { clip-path: inset(20% 0 80% 0); }
           20% { clip-path: inset(60% 0 10% 0); }
           40% { clip-path: inset(40% 0 50% 0); }
           60% { clip-path: inset(80% 0 5% 0); }
           80% { clip-path: inset(10% 0 70% 0); }
           100% { clip-path: inset(30% 0 20% 0); }
       }
       @keyframes glitch-anim-2 {
           0% { clip-path: inset(10% 0 60% 0); }
           20% { clip-path: inset(30% 0 20% 0); }
           40% { clip-path: inset(70% 0 10% 0); }
           60% { clip-path: inset(20% 0 50% 0); }
           80% { clip-path: inset(50% 0 30% 0); }
           100% { clip-path: inset(5% 0 80% 0); }
       }


       .glass-panel {
           background: rgba(0, 15, 5, 0.65);
           border: 1px solid var(--neon-dark);
           box-shadow: 0 0 20px rgba(0, 255, 65, 0.05), inset 0 0 30px rgba(0, 20, 0, 0.8);
           backdrop-filter: blur(12px);
           -webkit-backdrop-filter: blur(12px);
           position: relative;
           z-index: 10;
       }


       .glass-panel::before, .glass-panel::after {
           content: ''; position: absolute; width: 20px; height: 20px;
           border: 2px solid var(--neon-green); transition: all 0.3s ease;
       }
       .glass-panel::before { top: -1px; left: -1px; border-right: none; border-bottom: none; }
       .glass-panel::after { bottom: -1px; right: -1px; border-left: none; border-top: none; }
       .glass-panel:hover::before, .glass-panel:hover::after { width: 35px; height: 35px; box-shadow: 0 0 15px var(--neon-green); }


       .btn-cyber {
           background: rgba(0, 255, 65, 0.1);
           border: 1px solid var(--neon-green);
           position: relative;
           overflow: hidden;
           transition: all 0.2s;
       }
       .btn-cyber::before {
           content: ''; position: absolute; top: 0; left: -100%; width: 100%; height: 100%;
           background: linear-gradient(90deg, transparent, rgba(0,255,65,0.4), transparent);
           transition: all 0.4s;
       }
       .btn-cyber:hover::before { left: 100%; }
       .btn-cyber:hover {
           background: var(--neon-green);
           color: var(--bg-dark);
           box-shadow: 0 0 20px var(--neon-green);
       }


       .radar-container {
           width: 80px; height: 80px;
           border-radius: 50%;
           border: 2px solid var(--neon-dark);
           position: relative;
           overflow: hidden;
           box-shadow: 0 0 15px rgba(0, 255, 65, 0.2);
           background: repeating-radial-gradient(transparent, transparent 10px, rgba(0,255,65,0.1) 11px, rgba(0,255,65,0.1) 12px);
       }
       .radar-sweep {
           position: absolute; top: 0; left: 50%; width: 50%; height: 50%;
           background: linear-gradient(90deg, rgba(0,255,65,0.8) 0%, transparent 100%);
           transform-origin: bottom left;
           animation: sweep 2s linear infinite;
       }
       @keyframes sweep { 0% { transform: rotate(0deg); } 100% { transform: rotate(360deg); } }
       @keyframes slideIn { from { opacity: 0; transform: translateX(-30px); } to { opacity: 1; transform: translateX(0); } }
       .task-animate { animation: slideIn 0.4s cubic-bezier(0.175, 0.885, 0.32, 1.275) forwards; }


       ::-webkit-scrollbar { width: 4px; }
       ::-webkit-scrollbar-track { background: transparent; }
       ::-webkit-scrollbar-thumb { background: var(--neon-dark); }
       ::-webkit-scrollbar-thumb:hover { background: var(--neon-green); }
      
       /* Particle Canvas Layer */
       #particle-canvas {
           position: fixed;
           top: 0; left: 0;
           width: 100vw; height: 100vh;
           z-index: -18;
           pointer-events: none;
       }
   </style>
</head>
<body class="min-h-screen p-4 md:p-8 flex flex-col items-center">


       <div class="hidden md:block text-right text-xs text-green-800 font-mono bg-green-900/20 p-2 border border-green-900/50 backdrop-blur-sm rounded">
           <span class="text-[#00ff41]">STATUS: ONLINE</span><br>
           <span id="data-stream">MEM: 0x4A89 | CPU: 12%</span>
       </div>
   </header>


   <main class="w-full max-w-6xl grid grid-cols-1 md:grid-cols-12 gap-6 relative z-10">
      
       <!-- Left Column: Controls & Stats -->
       <div class="md:col-span-4 flex flex-col gap-6">
          
           <div class="glass-panel p-6 rounded-sm">
               <h2 class="text-xl border-b border-green-900 pb-2 mb-4 uppercase text-green-500 tracking-wider">System Status</h2>
              
               <div class="flex items-center gap-6 mb-6 bg-black/40 p-3 rounded border border-green-900/30">
                   <div class="radar-container shrink-0">
                       <div class="radar-sweep"></div>
                       <div class="absolute inset-0 flex items-center justify-center">
                           <div class="w-2 h-2 bg-green-400 rounded-full animate-pulse shadow-[0_0_8px_#00ff41]"></div>
                       </div>
                   </div>
                   <div class="text-xs text-green-500 tracking-widest flex-1">
                       <p class="mb-1 text-gray-400">BIOS_VER: 4.8.1</p>
                       <p class="mb-1 text-gray-400">SYNC_RATE: 144hz</p>
                       <p class="text-[#00ff41] animate-pulse">> CORE STABLE</p>
                   </div>
               </div>


               <div class="mb-5">
                   <div class="flex justify-between mb-1 text-sm">
                       <span class="text-green-400 font-bold">Mental Focus [MEM]</span>
                       <span id="focus-display" class="text-green-400 drop-shadow-[0_0_5px_#00ff41]">100%</span>
                   </div>
                   <div class="w-full bg-[#001100] h-3 border border-green-900 overflow-hidden relative">
                       <div id="focus-bar" class="bg-[#00ff41] h-full transition-all duration-700 shadow-[0_0_10px_#00ff41]" style="width: 100%"></div>
                   </div>
               </div>
               <div>
                   <div class="flex justify-between mb-1 text-sm">
                       <span class="text-[#00e5ff] font-bold">Physical Energy [PWR]</span>
                       <span id="energy-display" class="text-[#00e5ff] drop-shadow-[0_0_5px_#00e5ff]">100%</span>
                   </div>
                   <div class="w-full bg-[#000511] h-3 border border-[#003b55] overflow-hidden relative">
                       <div id="energy-bar" class="bg-[#00e5ff] h-full transition-all duration-700 shadow-[0_0_10px_#00e5ff]" style="width: 100%"></div>
                   </div>
               </div>
           </div>


           <div class="glass-panel p-6 rounded-sm">
               <h2 class="text-lg border-b border-green-900 pb-2 mb-4 uppercase text-green-500 tracking-wider">User Calibration</h2>
               <div>
                   <label class="block text-xs text-green-600 mb-2 uppercase">Baseline Capacity</label>
                   <select id="user-profile" class="w-full bg-black/60 border border-green-800 text-green-400 p-2 text-sm focus:outline-none focus:border-[#00ff41] transition-colors cursor-pointer appearance-none shadow-inner">
                       <option value="high">Elite (High Resilience / Low Drain)</option>
                       <option value="medium" selected>Standard (Medium Resilience)</option>
                       <option value="low">Novice (Low Resilience / High Drain)</option>
                   </select>
               </div>
           </div>


           <div class="glass-panel p-6 rounded-sm relative overflow-hidden">
               <!-- Decorative background moving icon -->
               <svg class="absolute -right-4 -bottom-4 w-32 h-32 text-green-900/20 animate-spin-slow" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="1"><path d="M12 2v20M17 5H9.5a3.5 3.5 0 0 0 0 7h5a3.5 3.5 0 0 1 0 7H6"/></svg>
              
               <h2 class="text-lg border-b border-green-900 pb-2 mb-4 uppercase text-green-500 tracking-wider relative z-10">Initialize Task</h2>
               <form id="task-form" class="flex flex-col gap-4 relative z-10">
                   <div>
                       <label class="block text-xs text-green-600 mb-1 uppercase">Designation</label>
                       <input type="text" id="task-name" required autocomplete="off" class="w-full bg-black/60 border border-green-800 text-green-400 p-2 text-sm focus:outline-none focus:border-[#00ff41] transition-colors shadow-inner" placeholder="e.g., Code Database">
                   </div>
                   <div>
                       <label class="block text-xs text-green-600 mb-1 uppercase">Class Instance</label>
                       <select id="task-type" class="w-full bg-black/60 border border-green-800 text-green-400 p-2 text-sm focus:outline-none focus:border-[#00ff41] transition-colors appearance-none shadow-inner">
                           <option value="deepwork">Deep Focus (-Focus)</option>
                           <option value="physical">Physical Training (-Energy)</option>
                           <option value="maintenance">Maintenance (+Focus, +Energy)</option>
                       </select>
                   </div>
                   <div class="flex gap-3">
                       <div class="w-1/2">
                           <label class="block text-xs text-green-600 mb-1 uppercase">Hours</label>
                           <input type="number" id="task-hours" min="0" max="24" value="1" class="w-full bg-black/60 border border-green-800 text-green-400 p-2 text-sm focus:outline-none focus:border-[#00ff41] shadow-inner">
                       </div>
                       <div class="w-1/2">
                           <label class="block text-xs text-green-600 mb-1 uppercase">Minutes</label>
                           <input type="number" id="task-minutes" min="0" max="59" value="30" step="5" class="w-full bg-black/60 border border-green-800 text-green-400 p-2 text-sm focus:outline-none focus:border-[#00ff41] shadow-inner">
                       </div>
                   </div>
                   <button type="submit" class="mt-2 w-full btn-cyber text-[#00ff41] font-bold py-3 px-4 text-sm tracking-widest uppercase shadow-[0_0_10px_rgba(0,255,65,0.2)]">
                       [ Inject to Queue ]
                   </button>
               </form>
           </div>
       </div>


       <!-- Middle Column: Active Tasks -->
       <div class="md:col-span-4">
           <div class="glass-panel p-6 rounded-sm h-full min-h-[500px] flex flex-col">
               <h2 class="text-xl border-b border-green-900 pb-2 mb-4 uppercase flex justify-between items-end text-green-500">
                   <span>Active Queue</span>
                   <span class="text-xs bg-green-900/50 px-2 py-1 rounded border border-green-800">VECT: <span id="task-count" class="text-[#00ff41]">0</span></span>
               </h2>
               <div id="task-list" class="flex flex-col gap-3 flex-grow overflow-y-auto pr-2">
                   <!-- Tasks injected here -->
                   <div class="flex-grow flex items-center justify-center">
                       <p class="text-green-800 text-sm italic opacity-50 flex items-center gap-2">
                           <span class="animate-pulse block w-2 h-2 bg-green-800 rounded-full"></span>
                           Awaiting instructions...
                       </p>
                   </div>
               </div>
           </div>
       </div>


       <!-- Right Column: OOP System Log -->
       <div class="md:col-span-4">
           <div class="glass-panel p-6 rounded-sm h-full flex flex-col relative overflow-hidden">
               <div class="absolute inset-0 bg-[url('data:image/svg+xml;base64,PHN2ZyB4bWxucz0iaHR0cDovL3d3dy53My5vcmcvMjAwMC9zdmciIHdpZHRoPSI0IiBoZWlnaHQ9IjQiPgo8cmVjdCB3aWR0aD0iNCIgaGVpZ2h0PSI0IiBmaWxsPSIjMDAwIiBmaWxsLW9wYWNpdHk9IjAuMSIvPgo8cGF0aCBkPSJNMCAwTDIgMk0yIDBMMCAyIiBzdHJva2U9IiMwMGZmNDEiIHN0cm9rZS1vcGFjaXR5PSIwLjAyIiBzdHJva2Utd2lkdGg9IjAuNSIvPgo8L3N2Zz4=')] opacity-50 pointer-events-none z-0"></div>
               <h2 class="text-xl border-b border-green-900 pb-2 mb-4 uppercase text-green-500 relative z-10">System Log</h2>
               <div id="system-log" class="flex-grow bg-black/80 border border-green-900/50 p-4 overflow-y-auto max-h-[600px] font-mono text-xs text-green-500 flex flex-col gap-2 shadow-inner relative z-10 rounded">
                   <span class="text-[#00e5ff] opacity-80">> BOOT SEQUENCE INITIATED...</span>
                   <span class="text-[#00ff41]">> Background video initialized.</span>
                   <span class="text-[#00ff41]">> Interactive Canvas Layer mounted.</span>
                   <span class="text-yellow-400">> OOP Core Classes Loaded. Awaiting input.</span>
               </div>
           </div>
       </div>


   </main>


   <script>
       // Decorative Data Stream logic for top right header
       setInterval(() => {
           const mem = Math.floor(Math.random() * 9000 + 1000).toString(16).toUpperCase();
           const cpu = Math.floor(Math.random() * 30 + 10);
           document.getElementById('data-stream').innerText = `MEM: 0x${mem} | CPU: ${cpu}%`;
       }, 1500);


       // --- INTERACTIVE BACKGROUND PARTICLES (CANVAS) ---
       const canvas = document.getElementById('particle-canvas');
       const ctx = canvas.getContext('2d');
       let particlesArray = [];
       const numberOfParticles = 80;


       canvas.width = window.innerWidth;
       canvas.height = window.innerHeight;


       let mouse = { x: null, y: null, radius: 150 };


       window.addEventListener('mousemove', function(event) {
           mouse.x = event.x;
           mouse.y = event.y;
       });


       class Particle {
           constructor() {
               this.x = Math.random() * canvas.width;
               this.y = Math.random() * canvas.height;
               this.size = Math.random() * 2 + 1;
               this.speedX = Math.random() * 1 - 0.5;
               this.speedY = Math.random() * 1 - 0.5;
           }
           update() {
               this.x += this.speedX;
               this.y += this.speedY;
               if (this.size > 0.2) this.size -= 0.01;
               if (this.x < 0 || this.x > canvas.width) this.speedX = -this.speedX;
               if (this.y < 0 || this.y > canvas.height) this.speedY = -this.speedY;


               // Mouse interaction
               let dx = mouse.x - this.x;
               let dy = mouse.y - this.y;
               let distance = Math.sqrt(dx * dx + dy * dy);
               if (distance < mouse.radius) {
                   this.x -= dx/20;
                   this.y -= dy/20;
               }
           }
           draw() {
               ctx.fillStyle = 'rgba(0, 255, 65, 0.5)';
               ctx.beginPath();
               ctx.arc(this.x, this.y, this.size, 0, Math.PI * 2);
               ctx.closePath();
               ctx.fill();
           }
       }


       function initCanvas() {
           particlesArray = [];
           for (let i = 0; i < numberOfParticles; i++) {
               particlesArray.push(new Particle());
           }
       }


       function animateCanvas() {
           ctx.clearRect(0, 0, canvas.width, canvas.height);
           for (let i = 0; i < particlesArray.length; i++) {
               particlesArray[i].update();
               particlesArray[i].draw();
               // Connect particles
               for (let j = i; j < particlesArray.length; j++) {
                   let dx = particlesArray[i].x - particlesArray[j].x;
                   let dy = particlesArray[i].y - particlesArray[j].y;
                   let distance = Math.sqrt(dx * dx + dy * dy);
                   if (distance < 100) {
                       ctx.beginPath();
                       ctx.strokeStyle = `rgba(0, 255, 65, ${0.2 - distance/500})`;
                       ctx.lineWidth = 1;
                       ctx.moveTo(particlesArray[i].x, particlesArray[i].y);
                       ctx.lineTo(particlesArray[j].x, particlesArray[j].y);
                       ctx.stroke();
                       ctx.closePath();
                   }
               }
           }
           requestAnimationFrame(animateCanvas);
       }
       initCanvas();
       animateCanvas();


       window.addEventListener('resize', function() {
           canvas.width = window.innerWidth;
           canvas.height = window.innerHeight;
           initCanvas();
       });




       // SVG Icon Library
       const Icons = {
           brain: `<svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M9.5 2A2.5 2.5 0 0 1 12 4.5v15a2.5 2.5 0 0 1-4.96.44 2.5 2.5 0 0 1-2.96-3.08 3 3 0 0 1-.34-5.58 2.5 2.5 0 0 1 1.32-4.24 2.5 2.5 0 0 1 1.98-3A2.5 2.5 0 0 1 9.5 2Z"/><path d="M14.5 2A2.5 2.5 0 0 0 12 4.5v15a2.5 2.5 0 0 0 4.96.44 2.5 2.5 0 0 0 2.96-3.08 3 3 0 0 0 .34-5.58 2.5 2.5 0 0 0-1.32-4.24 2.5 2.5 0 0 0-1.98-3A2.5 2.5 0 0 0 14.5 2Z"/></svg>`,
           lightning: `<svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="#00e5ff" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><polygon points="13 2 3 14 12 14 11 22 21 10 12 10 13 2"></polygon></svg>`,
           wrench: `<svg width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="#ffeb3b" stroke-width="2" stroke-linecap="round" stroke-linejoin="round"><path d="M14.7 6.3a1 1 0 0 0 0 1.4l1.6 1.6a1 1 0 0 0 1.4 0l3.77-3.77a6 6 0 0 1-7.94 7.94l-6.91 6.91a2.12 2.12 0 0 1-3-3l6.91-6.91a6 6 0 0 1 7.94-7.94l-3.76 3.76z"/></svg>`
       };


       // ==========================================
       // OOP PILLAR 1: ENCAPSULATION & ABSTRACTION
       // ==========================================
       class ProtocolEngine {
           #focusBank;
           #physicalEnergy;
           #tasks;
           #drainMultiplier;


           constructor() {
               this.#focusBank = 100;
               this.#physicalEnergy = 100;
               this.#tasks = [];
               this.#drainMultiplier = 1.0;
           }


           setProfile(level) {
               switch(level) {
                   case 'high': this.#drainMultiplier = 0.5; break;
                   case 'medium': this.#drainMultiplier = 1.0; break;
                   case 'low': this.#drainMultiplier = 1.5; break;
               }
               logSystem(`State Change: User Profile -> [${level.toUpperCase()}]. Multiplier updated to ${this.#drainMultiplier}x.`, 'text-[#00e5ff]');
           }


           addTask(task) {
               this.#tasks.push(task);
               logSystem(`Instantiated ${task.constructor.name}: "${task.name}"`);
               renderTasks();
           }


           getTasks() { return this.#tasks; }
           getStats() { return { focus: this.#focusBank, energy: this.#physicalEnergy }; }


           executeTask(taskId) {
               const taskIndex = this.#tasks.findIndex(t => t.id === taskId);
               if (taskIndex > -1) {
                   const task = this.#tasks[taskIndex];
                  
                   const result = task.execute();
                  
                   const finalFocusImpact = result.focusImpact < 0 ? (result.focusImpact * this.#drainMultiplier) : result.focusImpact;
                   const finalEnergyImpact = result.energyImpact < 0 ? (result.energyImpact * this.#drainMultiplier) : result.energyImpact;


                   this.#focusBank = Math.max(0, Math.min(100, this.#focusBank + finalFocusImpact));
                   this.#physicalEnergy = Math.max(0, Math.min(100, this.#physicalEnergy + finalEnergyImpact));
                  
                   logSystem(`EXECUTED: [${task.name}]. FOC: ${finalFocusImpact.toFixed(1)} | PWR: ${finalEnergyImpact.toFixed(1)}`, 'text-yellow-400');
                  
                   this.#tasks.splice(taskIndex, 1);
                   updateStatsUI();
                   renderTasks();


                   if (this.#focusBank === 0) logSystem("CRITICAL: Focus depleted. Logic errors likely.", "text-[#ff003c] font-bold bg-red-900/30 p-1");
                   if (this.#physicalEnergy === 0) logSystem("CRITICAL: Power depleted. System shutdown imminent.", "text-[#ff003c] font-bold bg-red-900/30 p-1");
               }
           }
       }


       // ==========================================
       // OOP PILLAR 2: INHERITANCE (Base Class)
       // ==========================================
       class ProtocolTask {
           constructor(name, hours, minutes) {
               this.id = Date.now().toString(36) + Math.random().toString(36).substr(2);
               this.name = name;
               this.hours = parseInt(hours) || 0;
               this.minutes = parseInt(minutes) || 0;
               this.totalMinutes = (this.hours * 60) + this.minutes;
           }
           execute() { return { focusImpact: 0, energyImpact: 0 }; }
           getIcon() { return Icons.brain; }
           getFormattedDuration() {
               let timeString = '';
               if (this.hours > 0) timeString += `${this.hours}h `;
               if (this.minutes > 0 || this.hours === 0) timeString += `${this.minutes}m`;
               return timeString.trim();
           }
       }


       // ==========================================
       // OOP PILLAR 3: POLYMORPHISM (Subclasses)
       // ==========================================
       class DeepWorkTask extends ProtocolTask {
           constructor(name, hours, minutes) { super(name, hours, minutes); }
           execute() {
               logSystem(`Polymorphism > DeepWork.execute() -> applying mental drain.`, 'text-gray-500');
               return { focusImpact: -(this.totalMinutes * 0.3), energyImpact: -(this.totalMinutes * 0.05) };
           }
           getIcon() { return Icons.brain; }
       }


       class PhysicalTask extends ProtocolTask {
           constructor(name, hours, minutes) { super(name, hours, minutes); }
           execute() {
               logSystem(`Polymorphism > Physical.execute() -> applying physical drain.`, 'text-gray-500');
               return { focusImpact: (this.totalMinutes * 0.1), energyImpact: -(this.totalMinutes * 0.35) };
           }
           getIcon() { return Icons.lightning; }
       }


       class MaintenanceTask extends ProtocolTask {
           constructor(name, hours, minutes) { super(name, hours, minutes); }
           execute() {
               logSystem(`Polymorphism > Maintenance.execute() -> applying restoration.`, 'text-gray-500');
               return { focusImpact: (this.totalMinutes * 0.25), energyImpact: (this.totalMinutes * 0.1) };
           }
           getIcon() { return Icons.wrench; }
       }


       // ==========================================
       // UI CONTROLLER & DOM MANIPULATION
       // ==========================================
       const system = new ProtocolEngine();


       const taskForm = document.getElementById('task-form');
       const taskList = document.getElementById('task-list');
       const systemLog = document.getElementById('system-log');
       const focusDisplay = document.getElementById('focus-display');
       const energyDisplay = document.getElementById('energy-display');
       const focusBar = document.getElementById('focus-bar');
       const energyBar = document.getElementById('energy-bar');
       const taskCount = document.getElementById('task-count');


       taskForm.addEventListener('submit', function(e) {
           e.preventDefault();
           const name = document.getElementById('task-name').value;
           const type = document.getElementById('task-type').value;
           const hours = document.getElementById('task-hours').value;
           const minutes = document.getElementById('task-minutes').value;


           if (hours == 0 && minutes == 0) {
               logSystem("ERROR: Null duration invalid.", "text-[#ff003c]");
               return;
           }


           let newTask;
           switch(type) {
               case 'deepwork': newTask = new DeepWorkTask(name, hours, minutes); break;
               case 'physical': newTask = new PhysicalTask(name, hours, minutes); break;
               case 'maintenance': newTask = new MaintenanceTask(name, hours, minutes); break;
               default: newTask = new ProtocolTask(name, hours, minutes);
           }


           system.addTask(newTask);
           document.getElementById('task-name').value = '';
           document.getElementById('task-name').focus();
       });


       function updateStatsUI() {
           const stats = system.getStats();
          
           focusDisplay.innerText = `${Math.floor(stats.focus)}%`;
           focusBar.style.width = `${stats.focus}%`;
          
           if(stats.focus < 30) {
               focusBar.classList.replace('bg-[#00ff41]', 'bg-[#ff003c]');
               focusDisplay.classList.replace('text-green-400', 'text-[#ff003c]');
               focusDisplay.classList.replace('drop-shadow-[0_0_5px_#00ff41]', 'drop-shadow-[0_0_5px_#ff003c]');
           } else {
               focusBar.classList.replace('bg-[#ff003c]', 'bg-[#00ff41]');
               focusDisplay.classList.replace('text-[#ff003c]', 'text-green-400');
               focusDisplay.classList.replace('drop-shadow-[0_0_5px_#ff003c]', 'drop-shadow-[0_0_5px_#00ff41]');
           }


           energyDisplay.innerText = `${Math.floor(stats.energy)}%`;
           energyBar.style.width = `${stats.energy}%`;
          
           if(stats.energy < 30) {
               energyBar.classList.replace('bg-[#00e5ff]', 'bg-[#ff003c]');
               energyDisplay.classList.replace('text-[#00e5ff]', 'text-[#ff003c]');
               energyDisplay.classList.replace('drop-shadow-[0_0_5px_#00e5ff]', 'drop-shadow-[0_0_5px_#ff003c]');
           } else {
               energyBar.classList.replace('bg-[#ff003c]', 'bg-[#00e5ff]');
               energyDisplay.classList.replace('text-[#ff003c]', 'text-[#00e5ff]');
               energyDisplay.classList.replace('drop-shadow-[0_0_5px_#ff003c]', 'drop-shadow-[0_0_5px_#00e5ff]');
           }
       }


       function renderTasks() {
           const tasks = system.getTasks();
           taskList.innerHTML = '';
           taskCount.innerText = tasks.length;


           if (tasks.length === 0) {
               taskList.innerHTML = `
               <div class="flex-grow flex items-center justify-center h-full min-h-[100px]">
                   <p class="text-green-800 text-sm italic opacity-50 flex items-center gap-2">
                       <span class="animate-pulse block w-2 h-2 bg-green-800 rounded-full"></span>
                       Queue empty.
                   </p>
               </div>`;
               return;
           }


           [...tasks].reverse().forEach((task, index) => {
               const taskDiv = document.createElement('div');
               const animationClass = index === 0 ? 'task-animate' : '';
              
               taskDiv.className = `border border-green-900 bg-black/60 p-3 flex justify-between items-center hover:border-[#00ff41] hover:bg-[#001100] transition-colors relative overflow-hidden group shadow-md ${animationClass}`;
              
               taskDiv.innerHTML = `
                   <div class="absolute left-0 top-0 bottom-0 w-1 bg-transparent group-hover:bg-[#00ff41] transition-colors"></div>
                   <div class="flex items-center gap-4 pl-2">
                       <div class="text-[#00ff41] opacity-70 group-hover:opacity-100 transition-opacity drop-shadow-[0_0_5px_rgba(0,255,65,0.5)]">
                           ${task.getIcon()}
                       </div>
                       <div>
                           <p class="font-bold text-[#00ff41] tracking-wide text-sm">${task.name}</p>
                           <p class="text-[10px] text-green-600 font-mono mt-1">CLASS: ${task.constructor.name} | T: ${task.getFormattedDuration()}</p>
                       </div>
                   </div>
                   <button onclick="executeTaskWrapper('${task.id}')" class="btn-cyber text-[#00ff41] px-4 py-2 text-xs font-bold tracking-widest rounded-sm">
                       EXECUTE
                   </button>
               `;
               taskList.appendChild(taskDiv);
           });
       }


       window.executeTaskWrapper = function(id) { system.executeTask(id); }


       function logSystem(message, colorClass = 'text-[#00ff41]') {
           const span = document.createElement('span');
           const time = new Date().toLocaleTimeString('en-US', { hour12: false, hour: '2-digit', minute:'2-digit', second:'2-digit' });
           span.className = colorClass;
           span.innerHTML = `<span class="opacity-50">[${time}]</span> <span class="animate-pulse">></span> ${message}`;
           systemLog.appendChild(span);
           systemLog.scrollTop = systemLog.scrollHeight;
       }


       document.getElementById('user-profile').addEventListener('change', function(e) {
           system.setProfile(e.target.value);
       });


       // Initialize UI
       updateStatsUI();


   </script>
</body>
</html>   <!-- 1. Live Background Video -->
   <video autoplay loop muted playsinline class="video-background">
       <source src="https://assets.mixkit.co/videos/preview/mixkit-software-developer-working-on-code-1563-large.mp4" type="video/mp4">
   </video>


   <!-- 2. Holographic Rings -->
   <div class="hologram-ring ring-1"></div>
   <div class="hologram-ring ring-2"></div>


   <!-- 3. Interactive Particles -->
   <canvas id="particle-canvas"></canvas>


   <!-- 4. CRT Overlay -->
   <div class="scanlines"></div>
   <div class="vignette"></div>


   <header class="w-full max-w-6xl mb-8 border-b border-green-900 pb-4 flex justify-between items-end relative z-10 pt-4">
       <div>
           <!-- Glitch Text applied here -->
           <h1 class="text-4xl md:text-5xl font-bold uppercase tracking-widest text-[#00ff41] glitch" data-text="Sys_Protocol.exe">Sys_Protocol.exe</h1>
           <p class="text-green-600 mt-2 text-sm tracking-widest flex items-center gap-2">
               <span class="w-2 h-2 bg-[#00ff41] rounded-full animate-ping"></span>
               // Object-Oriented Engine v3.0
           </p>
       </div>








