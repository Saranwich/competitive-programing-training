// Shared quiz component. Usage in a lesson:
//   <div class="quiz" id="quiz1"></div>
//   <script src="../assets/quiz.js"></script>
//   <script>renderQuiz("quiz1", [{stem, options: [..], answer: idx, explain}])</script>
// Options are shuffled on render; feedback is immediate.
function renderQuiz(id, questions) {
  const root = document.getElementById(id);
  let score = 0, answered = 0;
  const scoreEl = document.createElement("p");
  scoreEl.className = "score";
  questions.forEach((q, qi) => {
    const box = document.createElement("div");
    box.className = "q";
    const stem = document.createElement("p");
    stem.className = "stem";
    stem.textContent = (qi + 1) + ". " + q.stem;
    box.appendChild(stem);
    const order = q.options.map((_, i) => i).sort(() => Math.random() - 0.5);
    order.forEach(i => {
      const b = document.createElement("button");
      b.className = "opt";
      b.textContent = q.options[i];
      b.onclick = () => {
        box.querySelectorAll("button").forEach(x => (x.disabled = true));
        b.classList.add(i === q.answer ? "correct" : "wrong");
        if (i !== q.answer) {
          box.querySelectorAll("button").forEach((x, k) => {
            if (x.textContent === q.options[q.answer]) x.classList.add("correct");
          });
        } else score++;
        box.classList.add("answered");
        answered++;
        scoreEl.textContent = answered === questions.length
          ? `Score: ${score}/${questions.length}` + (score === questions.length ? " — perfect." : " — reread the missed rows, then retry (reload page).")
          : "";
      };
      box.appendChild(b);
    });
    const ex = document.createElement("p");
    ex.className = "explain";
    ex.textContent = q.explain || "";
    box.appendChild(ex);
    root.appendChild(box);
  });
  root.appendChild(scoreEl);
}
